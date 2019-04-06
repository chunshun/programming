计算触发比例的变化，需要算实时路况 和 挖掘eta。

---

挖掘ETA

path: /user/bigdata-dp/zhangzhiming/ranker_feature/ranker_log_etl_fulldata_beijing_with_wajueETA_modified/1_beijing/trip/2019/01/{01-11}

字段格式是：traceid \t orderid \t cityid \t 原有路线real_eta;替换路线real_eta \t start \t dest \t time \t hit_message \t yaw \t driver_id \t **原有top1路线**;准出替换路线(如果是触发不准出，top1路线和准出替换路线一样) \t links#dist#rank#score#挖掘ETA(召回所有路线的link，距离，排序，得分，挖掘ETA，路线之间用 ; 分割) \t 替换路线的挖掘ETA;**原有top1路线的挖掘ETA**（如果没有替换的话两者相同）\t 订单终止时间 \t 司机当前时刻到终点的轨迹geo序列


example:



---

chenji_cch_v2 _估价+准出+ *触发*

--- 

CCH_v2 准出


避堵条件：先check挖掘eta，再check实时路况。
具体逻辑参考：https://git.xiaojukeji.com/geomining/route-ranker/blob/master/src/ranker_strategy/src/fast_congestion.cpp, 中的方法：triggerStrategyTwo.

1. 当前路线 实时ETA - 挖掘 ETA > 120s

2. 引入实时路况，
   1）极拥堵路段距离超过250m且该距离不少于全程距离的1%，或超过整条路线的5%（行程中以剩余距离作为分母）；
   2）极拥堵+拥堵路段超过500m且该距离不少于全程距离的1%，或超过整体路线的10%；
   3）极拥堵+拥堵路段+缓行路段超过1000m且该距离不少于全程距离的1%，或超过整体路线的20%；

计算长度时候，不考虑link首尾截断。

---
link的实时路况数据
/user/xinsi_traffic/swan/china/bizlog/export_citycode/1
date,time,link_id,rule_status,rule_status_speed,eta_speed,conf,car_count,length,data_version,model_status,model_status_speed

time为 HHmmss, 2分钟一次。

---

20190101,000000,6627840,1,40.9,26.0,96,17,10,2018122718,1,41.0
20190101,000000,143667101,1,43.1,42.6,80,8,170,2018122718,1,43.1
20190101,000000,500341061,1,21.0,21.1,19,1,5,2018122718,1,23.5
20190101,000000,3721320,1,23.5,23.5,5,3,12,2018122718,1,24.9
20190101,000000,5687660,0,0.0,7.1,3,1,34,2018122718,0,0.0
20190101,000000,90000000202971,0,0.0,21.0,0,1,167,2018122718,0,0.0
20190101,000000,4581261,1,46.1,43.2,98,14,120,2018122718,1,46.1
20190101,000000,6744220,1,36.7,32.0,99,17,33,2018122718,1,36.9
20190101,000000,8022341,1,49.6,49.6,5,6,15,2018122718,1,49.6
20190101,000000,551264060,1,49.3,56.5,71,7,14,2018122718,1,49.2

---

rule_status, 拥堵等级
0 - 未知。当成1
1 - 畅通
2 - 缓行
3 - 拥堵
4 - 极度拥堵


全量case中hit_message的例子。先算首次避堵的情况：即分母为首次避堵例子中的全部；分子为用原有top1路线的新的实时eta计算的触发成功率。 



实时ETA：assemble_eta wensheng



**prervious_top1**:    avoid_t(raffic 当前路线 实时ETA - 挖掘 ETA > 120s)


12  分母

新法则：
挖掘ETA-，，，，，


旧法则：
分子：8种条件


---

**原始路线数据集**

路径：/user/bigdata-dp/zhangzhiming/ranker_feature/ranker_log_etl_fulldata_beijing/0_quanguo/trip/2019/01/{07-11}

格式：traceid \t orderid \t cityid \t 原有路线real_eta;替换路线real_eta \t start_point请求od起点 \t dest_point请求od终点 \t **request_time** \t **hit_message** \t yaw \t driver_id \t 原有top1路线;准出替换路线(如果是触发不准出，top1路线和准出替换路线一样) \t links#dist#rank#score(召回所有路线的link，距离，排序和得分，路线之间用 ; 分割) \t 司机当前时刻到终点的轨迹geo序列

example:
```




```


格式：traceid \t orderid \t cityid \t 原有路线real_eta;替换路线real_eta \t start_point请求od起点 \t dest_point请求od终点 \t **request_time** \t **hit_message** \t yaw \t driver_id \t 原有top1路线;准出替换路线(如果是触发不准出，top1路线和准出替换路线一样) \t links#dist#rank#score(召回所有路线的link，距离，排序和得分，路线之间用 ; 分割) \t 司机当前时刻到终点的轨迹geo序列

需要筛选的case集：
首次避堵准出 hit_message== "FR_2_b" && yaw == 0
首次避堵触发未准出 hit_message.contains("FR_2_b_trigger_success"） && yaw == 0
偏航避堵准出 hit_message== "FR_2_b" && yaw == 1
偏航避堵触发未准出 hit_message.contains("FR_2_b_trigger_success"） && yaw == 1
行程中避堵准出 hit_message== "DR_2_b" && yaw == 0
行程中避堵触发未准出 hit_message.contains("DR_2_b_trigger_success"） && yaw == 0


---
link路况数据： /user/xinsi_traffic/swan/china/bizlog/export_citycode/1
格式：date,**time**,link_id,rule_status,rule_status_speed,eta_speed,conf,car_count,length（link长度，单位：m）,data_version（地图版本）,model_status,
//  20190101,**000000**,6627840,1,40.9,26.0,96,17,10,2018122718,1,41.0


```
234000
234200
234400
234600
234800
235000
235200
235400
235600
235800

```
---
tag

1. tag.contains("FR_2_b_T")
2. tag.contains("FR_2_b_trigger_success")
3. tag=="FR_2_b"


---





---
res
7
589262 1745097 0.3376672

8
717824 1846606 0.38872612

9
696939 1840744 0.3786181

10
749393 1839544 0.40737978

11
779735 1948468 0.4001785


--- 
flag


val line_split=line.split(",")
      val link_id=line_split(2)
      val time=line_split(1)
      val link_length=line_split(8).toLong
      val model_status=line_split(10).toInt
