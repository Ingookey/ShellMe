import os
import sys
import yaml


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


if __name__ == '__main__':
    list_para = sys.argv[1:]
    para_product = ""
    if list_para and len(list_para) == 1:
        para_product = list_para[0]

    file_yaml = parse_config(para_product)
    if not file_yaml:
        sys.exit(1)
    cur_path = os.path.dirname(os.path.realpath(__file__))
    yaml_path = os.path.join(cur_path, file_yaml)
    file_path = os.path.join(os.path.dirname(os.path.abspath("__file__")), file_yaml)
    yaml_fp = YamlHandler(yaml_path)
    yaml_data = yaml_fp.get_ymal_data()

    if True:
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