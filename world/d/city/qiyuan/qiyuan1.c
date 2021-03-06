//棋苑

#include <ansi.h>
inherit  ROOM;

string look_string();

void  create  ()
{
    set  ("short",  "棋苑");
    set  ("long", 
"棋苑共分四个大间，是手谈休栖的好地方。这里的南北和西三个方
向各有一间棋室，在每个棋室的门外都贴着"HIY"请勿打扰棋局"NOR"的
牌子，在房间中央的柱子上还贴着一张下棋指南(help)。
");

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("no_magic", "1");
         set("no_perform", "1");
         set("pingan",1);
         set("no_beg",1); 	
    set("item_desc", ([
    "help" : ( : look_string : ),
    ]));

    set("exits",  ([
    "east"  :  __DIR__"qiyuan2",
    "south"  :  __DIR__"qiyuan3",
    "north"  :  __DIR__"qiyuan4",
    "west" : "/d/city/clubpoem",
    ]));

     set("objects",  ([
    __DIR__"cch"  :  1,
    ]));
   setup();
}

string look_string()
{
	string  msg  =  "[5m[1;32m欢迎[2;37;0m[1;31m您[2;37;0m来下[1;36m象棋！[2;37;0m\n"  +
"
———————————————————————————
[1;36m中国象棋[2;37;0m（cchess）
———————————————————————————
下子   ：[1;33mmove[2;37;0m [37m<横座标> <纵座标>[2;37;0m [1;33mto[2;37;0m [37m<横座标> <纵座标>[2;37;0m
重下      ：[1;33mreset[2;37;0m
读出残局  ：[1;33mdeploy[2;37;0m
记录残局  ：[1;33mcsave[2;37;0m
掷骰      ：[1;33mtoss[2;37;0m
回顾      ：[1;33mreview[2;37;0m
认输   ：[1;33mlose[2;37;0m


";
	return  msg;
}

int valid_leave(object me, string dir)
{
        object room;
        mapping exit;

        exit = environment(me)->query("exits");

        if ( dir == "south" || dir == "north" || dir == "west" ) {
                if( !( room = find_object(exit[dir])) )
                       room = load_object(exit[dir]);
	        if( room->query_temp("action")  ==  1 )
                       return notify_fail("那间棋室已经有人开始下棋了，请勿打扰\n");
                }

        return ::valid_leave(me, dir);
}
