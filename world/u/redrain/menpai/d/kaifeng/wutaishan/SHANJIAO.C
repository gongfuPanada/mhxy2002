#include <ansi.h>
inherit ROOM;

void create()
{
set("short", "��̨ɽ����");
set("long", @LONG
    

�����Ӵ��Ա��ķ�Բ�������Ͷ�����̨ɽ�ˣ���������ɽ�壬
��幰�����࣬��ɽ�ȴ�����ϰϰ����ʹ���С��صĹ�������
�������������ɫ����ʩ�ɡ�

LONG );


set("exits", ([
  "northup"   : __DIR__"qinglianggu",
  "south"   : __DIR__"guandao1",
    "northeast" : "/d/12gong/toby1",
 
]));

set("objects", ([ 
]));

set("outdoors", 1);
setup();
}

int valid_leave(object me, string dir)
{
      if(me->query("combat_exp") < 2500000 && dir=="northeast")
       return notify_fail(HIY"�����ڵ���ѧ��Ϊ��û���ʸ���ŵ��ȣ�\n"NOR);
      if(me->query("12gong/number") >= 12 && !me->query("12gong/all") || dir=="northeast" && !wizardp(me))
       return notify_fail(HIR"�㲻���Ѿ�����12������\n"NOR);
       return ::valid_leave(me, dir);
  }