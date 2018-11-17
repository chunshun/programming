jsonStr = '{"one" : "1", "two" : "2", "three" : "3","four":{
    "four_1":'1',
    "four2":'2'
}}'
import json
# print(json.loads(jsonStr)["one"])
j=json.loads(jsonStr)
print(j["one"],j["four"])

