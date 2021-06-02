

from xml.dom.minidom import parse
from openpyxl import Workbook


def inlet():
    DOMTree = parse('conf.xml')
    collection = DOMTree.documentElement

    if collection.hasAttribute('shelf'):
        print('Root element is ', collection.getAttribute('shelf'))

    movies = collection.getElementsByTagName('movie')
    all_movies = []
    for movie in movies:
        item_movie = []
        my_list = []
        if movie.hasAttribute('title'):
            item_movie.append(movie.getAttribute('title'))

        for node in movie.childNodes:
            my_list.append(node.nodeName)
        
        type = movie.getElementsByTagName('type')[0]
        item_movie.append(type.childNodes[0].data)
        
        format = movie.getElementsByTagName('format')[0]
        item_movie.append(format.childNodes[0].data)

        if 'year' in my_list:
            year = movie.getElementsByTagName('year')[0]
            item_movie.append(year.childNodes[0].data)

        rating = movie.getElementsByTagName('rating')[0]
        item_movie.append(rating.firstChild.data)

        stars = movie.getElementsByTagName('stars')[0]
        item_movie.append(stars.childNodes[0].data)

        description = movie.getElementsByTagName('description')[0]
        item_movie.append(description.childNodes[0].data)
        print("{} info: {}".format(movie, item_movie))
        all_movies.append(item_movie)
    pass

    if True:
        wb = Workbook()
        ws = wb.active
        for item in all_movies:
            ws.append(item)
        wb.save(r'book.xlsx')
    pass


if __name__ == '__main__':
    inlet()
    pass



