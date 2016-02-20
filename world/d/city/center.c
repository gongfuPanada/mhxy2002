//changan city
//by tianlin@mhxy 2001/9/3
//设定一点难度,比如说可以加上climb的要求,什么dodge 100才能爬...等等
//或者是wx<多少不能爬一类的,我设上这么个东西主要是为了好玩,有点新鲜感
//我在次就只设一个wx的要求吧,大家可以参考这做一下修改,但请不要该作者的名字
//谢谢!!!!!!
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short","十字街头");
        set ("long", @LONG

这里便是长安城的中心，四条大街交汇于此。一座巍峨高大的钟楼耸
立于前，很是有些气势。每到清晨，响亮的钟声便会伴着淡淡雾气传
向长安城的大街小巷。路口车水马龙，来往人潮不断。路边不知什么
时候种了一颗[1;32m大榕树[2;37;0m[1;33m(tree)[2;37;0m，盘根错节，已经很有一段历史了。
LONG);
set("item_desc", ([ /* sizeof() == 2 */
  "tree" : "一棵高大无比的大树,你可以上去看看"HIG"(climb tree)"NOR"\n",
  "up": HIY"树上云雾缭绕，什么也看不清楚。\n"NOR,
]));

        set("exits", 
        ([ //sizeof() == 4
//		"enter" : "/d/biwu/biwu.c",
		"south" : __DIR__"zhuque-s1",
              "north" : __DIR__"xuanwu-n0",
"up" : "/d/liwu/happyjie",
               "west" : __DIR__"baihu-w1",
               "east" : __DIR__"qinglong-e1",
               "down" : __DIR__"droproom",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/libai" : 1,
                __DIR__"npc/paimaishi" : 1,
               // __DIR__"npc/vikee" : 1,
              "/d/qujing/wuzhuang/npc/zhangguolao": 1,
                "/u/tianlin/table" : 1,
                "/u/tianlin/bei":1,
        ]));

       set("outdoors", "changan");
	set("no_clean_up", 0);
       setup();
	//replace_program(ROOM);
       }
void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="tree" && arg!="树") )
		return notify_fail(HIG"你要爬什么？\n"NOR);
	if(me->is_busy())
		return notify_fail(YEL"你很忙，爬什么呀！\n"NOR);
       if(me->query("combat_exp")<20000)
              return notify_fail(HIC"就凭你现在的本事也想爬上去.\n还是在练两年吧!\n"NOR);
	message_vision(HIY"$N慢慢的往树顶爬去,一步一步小心前进... \n"NOR, me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(CYN"$N越爬越高，突然看见一座房子 ... \n"NOR, me);
	me->move("/d/city/jiuguan1");
	message_vision(WHT"$N慢慢的爬了上来。\n"NOR, me);
	return 1;
}

/*
int valid_leave (object who, string dir)
{
  if (dir == "up")
    return notify_fail (HIR"你看了看,走是走不上去的,只有爬上去还有点可能性。\n"NOR);
  return ::valid_leave(who,dir);
}
*/



