// tian5.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "第八重天·月影天");
  set ("long", @LONG

                         s________________s         
                        /LLLLLLLLLLLLLLLLLL\        
    []__[]             ^^||======||======||^^             []__[]
    []==[]_[]__[]__[]__[]||[]__[]||[]__[]||[]__[]__[]__[]_[]==[]
    []==[]|__|__|__|__|__|__|┏━━━┓_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_┃[1;36m八重天[0m┃__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__|┗━━━┛_|__|__|__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|__/       \__|__|__|__|__|__|_[]==[]
    []==[]|__|__|__|__|__|__||        | |_|__||__|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__┌┐┌┐_|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|└┘└┘|__|__|__[]==[]
    []==[]__|__|__|__|__|__|_|        |__|__|__|__|__|__|_[]==[]
    []==[]_|__|__|__|__|__|__|        |_|__|__|__|__|__|__[]==[]
                   依月傍影华之秀  客来随缘敬上茶
这里就是第八重天·月影天·
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"midong8",
  "south" : __DIR__"road8",

]));
  set("objects", ([
             __DIR__"npc/tianjiang" : 2,
        ]));
        set("no_clean_up", 0);
        setup();

}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me=this_player();
        
        if( !arg || (arg!="sky" && arg!="天") )
                return notify_fail("你要爬什么？\n");
        if(me->is_busy())
                return notify_fail("你很忙，爬什么呀！\n");

        message_vision("$N搓了搓手，顺着云路往上爬... \n", me);
        me->start_busy(3);

        if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
                call_out("faila", 3, me);
                return 1;
        }

        if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=100 ){
                call_out("faila", 3, me);
                return 1;
        }

        call_out("success", 3, me);
        return 1;
}
int success(object me)
{
        message_vision("$N越爬越高，渐渐隐入了云中 ... \n", me);
        me->move("/d/guzhanchang/road9");
        me->receive_damage("kee", 400);
        me->receive_damage("sen", 400);
        message_vision("$N慢慢的爬了上来。\n", me);
        return 1;
}
int faila(object me)
{

        tell_object(me, "你手上一个不稳，从云中掉了下来 ... \n");
        tell_room(environment(me), me->name()+"晃悠悠的从云中掉了下来。\n", ({me, me}));
        
me->unconcious();
        return 1;
}

int valid_leave(object me, string dir)
{       
        object a;
        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("tianjiang", environment(me))) && living(a) )
                return notify_fail("天将好象不愿让你过去！\n");
        return ::valid_leave(me, dir);
        }

        return 1;
}







