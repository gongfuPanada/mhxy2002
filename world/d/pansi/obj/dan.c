//By tianlin@mhxy for 2001.9.13
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIC "叛师丹" NOR, ({"panshi dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", HIC"碧油油的一颗丹药。\n"NOR);
    set("value", 50000000);
    set("no_sell", 1);
    set("rumor_msg",1);
  }
  
  setup();
}

void init()
{
        add_action("do_eat", "eat");
}


int do_eat(string arg)
{
  object me = this_player();
  string msg; 
  if (!id(arg))
    return notify_fail("你要吃什么？\n");

        message_vision(HIC"$N吃下一颗叛师丹，脸色变的一片惨白。过去的事情仿佛一片空白。。。\n"NOR, me);  
  
        me->add("bellicosity", -random( (int)me->query_kar() * 10));
        if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);

        me->delete("family");
        me->delete("class");
        me->set("title", "普通百姓");
        me->delete("betray");
        me->save();
        msg="有人看见"+ me->query("name")+ "偷吃了一颗叛师丹！\n";
      CHANNEL_D->do_channel(this_object(),"sys",msg);
  destruct(this_object());
  return 1;
}
