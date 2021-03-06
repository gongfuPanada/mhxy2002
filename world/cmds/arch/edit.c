// By tianlin 2001.5.1
// edit.c
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
mixed query(string arg)
{
    if (arg && arg=="channel_id")
      return  RED"在线编辑(Edit)";
    return 0;
}
int main(object me, string file)
{
    string filename;
    if( !file ) return notify_fail("指令格式：edit <档名>\n");
    if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");
    filename=resolve_path(me->query("cwd"), file);
    if (!(int)SECURITY_D->valid_write(filename,me,"write"))
            return notify_fail("你没有足够的读写权利。\n");
    foreach (object user in users())
        if (filename == "/"+in_edit(user) )
            return notify_fail("共享冲突："+user->name(1)+"("+capitalize(user->query("id"))+")"+"正在编辑该文件("+filename+")。\n");
    printf("编辑文件：%s\n",filename);
CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)正在线编辑(%s)。"
,me->name(1),capitalize(me->query("id")),filename));
    log_file("edit/"+geteuid(me), sprintf("edit %s %s\n", resolve_path(me->query
("cwd"), file), ctime(time())) );
    seteuid(geteuid(me));
    ed(resolve_path(me->query("cwd"), file));
    me->set("cwf",filename);
    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : edit <档名>, edit here
利用此一指令可直接在线上编辑档案。
[36m/ 前向查找你后面所跟着的字符，比如/酒袋
? 后向查找你后面所跟着的字符
= 显示当前行是第几行
a 在当前行后新增加一行
A 类似'a'命令，但是将翻转自动缩进模式
c 将当前行内容覆盖掉输入新编辑内容
d 删除指定范围的行
e 退出当前档案, 开始编辑另一档(档案改变过未存盘无效)
E 类似'e'命令，但是文件被修改过也有效
f 显示或改变文件名
g 查找匹配行并对其执行相应命令
h 帮助文件(就是显示你现在看到的这些信息，可能是英文)
i 在当前行前面插入一行
I 排版整个代码 (Qixx version 1.0)
j 合并行，系统默认是将后续行连接到当前行
k 标记当前行- later referenced as 'a
l 显示指定行(可显示控制字符)
m 移动指定行(或几行)到指定位置
n 行号显示切换开关
O 同命令'i'
o 同命令'a'
p 输出指定范围行
q 退出编辑器
Q 退出编辑器，即使文件已经被修改且未存盘
r 在文件尾或指定行后读进另一文件
s 查找并替换(只对当前行第一个查找的字符串进行替换)
set 查询，改变和保存编辑器的设定值
t 复制指定行到指定位置
v 搜索并对不匹配行执行指定命令
x 保存文件并退出
w 将编辑的内容写到当前文件或指定的文件里
W 类似'w'命令，但是是将编辑的内容附加到指定或当前文件后
z 显示20行，可用参数 . + -
Z 显示40行，可用参数 . + -[2;37;0m[4;53m[1;37m[5m这些是教会你怎么使用edit指令.[2;37;0m
[4;53m[41m[1;33mBy tianlin 2001.5.1[2;37;0m
HELP
    );
    return 1;
}
