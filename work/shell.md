- shell parallel
```shell
#!/bin/bash
# Our custom function
cust_func(){
wget -q "$1"
} 
while IFS= read -r url
do
  cust_func "$url" &
done < list.txt
wait
echo "All files are downloaded."

```
- get the file absolute path
```shell
realpath test.txt
#or
echo "$(cd "$(dirname "$1")"; pwd -P)/$(basename "$1")"
```
- `du` get the filename only
```shell
du -Sh ./* | sort -rh|head |cut  -f 2
```
- `**` operator
```shell
wc -l ./**/*.scala
```
- odd/even number
```shell
sed -n 2~2p filename
```