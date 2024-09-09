import requests
url = "https://jsonplaceholder.typicode.com/posts"
data = {"userId": 1, "id": 1, "title": "test title", "body": "test body"}
response = requests.put(url, json=data)
id = response.json()["id"]
url_with_id = url + "/" + str(id)
response = requests.get(url_with_id)
if response.status_code == 200:
   print(response.json()["title"])
else:
   print("Error")