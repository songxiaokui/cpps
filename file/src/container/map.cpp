//
// Created by 宋晓奎 on 2024/1/18.
//

#include "map.h"
void testMap()
{
    // 创建 map
    map<string, int> mp;

    // 添加元素
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    // 查询元素
    cout << mp["one"] << endl;

    // 判断元素是否存在
    // count统计 key 出现的次数
    if (mp.count("x") > 0)
    {
        cout << "元素 x 存在" << endl;
    } else {
        cout << "元素 x 不存在" << endl;
    }

    // 迭代器遍历 map
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << "key: " << iter->first << " Value: " << iter->second << endl;
    }

    // 按数据对插入
    mp.insert(pair("four", 4));

    // 删除元素
    // 按 key 删除
    // mp.erase("four");
    // 按位置删除
    cout << mp["four"] << endl;
    mp.erase(mp.find("four"));
    cout << mp["four"] << endl;

    // 迭代器查找元素
    auto iter = mp.find("five");
    if (iter != mp.end())
    {
        cout << "元素 five 存在" << endl;
    } else {
        cout << "元素 five 不存在" << endl;
    }

    // for循环遍历 map
    for (const auto& iter: mp)
    {
        cout << "key: " << iter.first << " Value: " << iter.second << endl;
    }

    // 判断 map 是否为空
    cout << mp.empty() << endl;

    // 反向遍历
    for (auto riter = mp.rbegin(); riter != mp.rend(); riter++)
    {
        cout << "key: " << riter->first << " Value: " << riter->second << endl;
    }
}