inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "÷��֮��");
        set("long", @LONG
���¿�֦���飬����֨֨����÷�����Ʈ�裬�������¡�
ż��һ������У����������������������������Ӱ�ζ���
Զ��һᦰ�����緭�ɰڶ���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road",
  "north" : __DIR__"cright",

]));
        set("outdoors", "wanmei");
        set("coor/x",120);
        set("coor/y",-400);
        set("coor/z",30);
        setup();
}
void init()
{
        if(interactive(this_player()))
        {
                remove_call_out("dropleaf");
                call_out("dropleaf",random(10)+10,this_player());
        }
}

int dropleaf(object me)
{
        object leaf;
        if(me)
        if(environment(me) == this_object())
        {
                tell_object(me,"[31mһ��÷�����Ʈ�£�������[0m\n");
                leaf = new(__DIR__"obj/leaf");
                leaf->move(this_object());      
        }
}

