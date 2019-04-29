- generate time range
```sh
startdate=2013-03-15
enddate=2013-05-14

curr="$startdate"
while true; do
    [ "$curr" \< "$enddate" ] || { echo "$curr"; break; }
    echo "$curr"
    curr=$( date +%Y-%m-%d --date "$curr +1 day" )
done
```