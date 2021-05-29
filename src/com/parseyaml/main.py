import os
import sys
import yaml
import sqlite3


class YamlHandler:
    def __init__(self, file, encoding='utf-8'):
         self.file = file
         self.encoding = encoding

    def get_ymal_data(self):
        with open(self.file, encoding=self.encoding) as fp:
            data = yaml.load(fp.read(), Loader=yaml.FullLoader)
        return data

    def write_yaml(self, data):
        with open(self.file, 'w', encoding=self.encoding) as fp:
            yaml.dump(data, stream=fp, allow_unicode=True)
        pass


def parse_config(section_product):
    from configparser import ConfigParser

    cur_path = os.path.dirname(os.path.realpath(__file__))
    file_config = os.path.join(cur_path, 'conf.ini')
    config = ConfigParser()
    config.read(file_config)
    
    if config.sections():
        if section_product in config.sections():
            print(config.items(section_product))
            return config.get(section_product, 'file')
    return None


class LocalSql(object):
    def __init__(self, name_db='local.db', name_table='local'):
        self.name_db = os.path.join(os.path.dirname(os.path.abspath("__file__")), name_db)
        self.name_table = name_table
        print(self.name_db)

    def init_db(self):
        conn = sqlite3.connect(self.name_db)
        cursor = conn.cursor()
        sql = '''SELECT tbl_name FROM sqlite_master WHERE type = 'table' '''
        cursor.execute(sql)
        values = cursor.fetchall()
        tables = []
        for item in values:
            tables.append(item[0])

        if self.name_table not in tables:
            sql = '''CREATE TABLE IF NOT EXISTS ''' + self.name_table + ''' (
                _id INTEGER PRIMARY KEY AUTOINCREMENT,
                product TEXT,
                config_file TEXT,
                weiht FLOAT
                )'''
            cursor.execute(sql)
            cursor.close()
            print(self.name_table + ' 创建成功')
        else:
            print(self.name_table + ' 已经存在')
        pass

    def update_db(self):
        conn = sqlite3.connect(self.name_db)
        cursor = conn.cursor()
        insert_data = [('pt1', 'pt1.yaml', 3.0), ('pt2', 'pt2.yaml', 4.0)]

        #cursor.execute("INSERT INTO {} (product, config_file, weiht) \
        #    VALUES ('pt1', 'pt1.yaml', 1.0)".format(self.name_table))
        #cursor.execute("INSERT INTO {} (product, config_file, weiht) \
        #    VALUES ('pt2', 'pt2.yaml', 2.0)".format(self.name_table))
        if True:
            sql = "INSERT INTO {} (product, config_file, weiht) VALUES (?, ?, ?)".format(self.name_table)
            cursor.executemany(sql, insert_data)
        sql = "UPDATE {} SET config_file=?, weiht=? WHERE product=?".format(self.name_table)
        cursor.execute(sql, ('pt1.yaml', 7, 'pt1'))
        conn.commit()
        cursor.close()
        conn.close()

    def query_db(self):
        conn = sqlite3.connect(self.name_db)
        cursor = conn.cursor()
        sql = "select * from {}".format(self.name_table)
        #sql = "select product, config_file from {}".format(self.name_table)
        results = cursor.execute(sql)
        list_results = results.fetchall()
        if list_results:
            for item in list_results:
                print("result: {}".format(item))
        cursor.close()
        conn.close()

def test():
    ls = LocalSql()
    ls.init_db()
    ls.update_db()
    ls.query_db()
    pass

if __name__ == '__main__':
    list_para = sys.argv[1:]
    para_product = ""
    if list_para and len(list_para) == 1:
        para_product = list_para[0]

    file_yaml = parse_config(para_product)
    test()
    if not file_yaml:
        sys.exit(1)
    cur_path = os.path.dirname(os.path.realpath(__file__))
    yaml_path = os.path.join(cur_path, file_yaml)
    file_path = os.path.join(os.path.dirname(os.path.abspath("__file__")), file_yaml)
    print(file_path, os.path.abspath("__file__"))
    yaml_fp = YamlHandler(yaml_path)
    yaml_data = yaml_fp.get_ymal_data()

    if False:
        for it in range(len(yaml_data['SIGN_FILE_LIST'])):
            for item in yaml_data['SIGN_FILE_LIST'][it].values():
                if item is not None:
                    print(dict(item).get('FILE_NAME'))
    pass

    if False:
        yaml_data['SIGN_FILE_LIST'][0]['BIN_FILE1']['FILE_NAME'] = '修改2'
        yaml_fp.write_yaml(yaml_data)
        print(yaml_data)
        print(type(yaml_data))
    pass