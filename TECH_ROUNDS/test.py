
import requests
# import json
# response = requests.get(
#     'https://jsonmock.hackerrank.com/api/articles')
# data = response.json()
# # log data
# print(json.dumps(data, indent=4))


def topArticles(limit):
    # get data from the API
    response = requests.get(
        'https://jsonmock.hackerrank.com/api/articles')
    data = response.json()

    # get total pages
    total_pages = data['total_pages']

    # get all articles from each page
    articles = []
    for page in range(1, total_pages + 1):
        response = requests.get(
            'https://jsonmock.hackerrank.com/api/articles?page=' + str(page))
        data = response.json()
        articles.extend(data['data'])

    # ignore rows with no title or story_title
    articles = [article for article in articles if (article['title']
                or article['story_title']) and article['num_comments'] != None and article['num_comments'] != 0]

    # sort the articles by num_comments, if comment same then by title
    articles.sort(key=lambda x: (x['num_comments'], x['title']), reverse=True)

    titles = []
    for article in articles[:limit]:
        titles.append(article['title'] if article['title']
                      else article['story_title'])
    return titles


print(topArticles(2))

# sort on basis of num_comments decending and name alphabetically ignore None
# articles.sort(key=lambda x: (-x['num_comments']))
