//By tianlin@mhxy for 2001.9.10作了点修改
// 红包

#include <ansi.h>
inherit ITEM;
int do_open(string arg);
     
    string *red1_object=({
                   "/d/liwu/obj/goldcard.c",
                      });
              

void create()
{
	set_name(HIR"红包"NOR, ({"hong bao", "bao", "hong"}));
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用红纸制作而成的"+HIR"红包，"NOR+"似乎可以撕开(tearoff)。\n");
		set("unit", "个");
		set("value", "500000");
	}
}


   void init()
  { if(query("teared"))return;
//    set("no_get","每个人只有一个，不要这么贪心！\n");
//    set("no_drop","这么珍贵的东西你也扔？！\n")
    add_action("do_open","tearoff");
  }

   

  int do_open(string arg)
  { 
      object me=this_player(),ob;
         int rand;

    if(query("teared"))              
         return 0;
    set("teared",1);
    set("value", "100");

//    set("no_give",0)
//    set("no_get",0);
//    set("no_drop",0)

    set("long", "一个用红纸制作而成的"+HIR"红包，"NOR+"已经被撕开了。\n");
        if(me->query("gender")=="男性")
    tell_object(me,"你迫不及待地将"+HIR+"红包"NOR+"撕开，\n");
        else
    tell_object(me,"你小心翼翼地将"+HIR+"红包"NOR+"打开，\n");



      if(rand<sizeof(red1_object))
      {
           ob=new(red1_object[rand]);
            if(!ob)
             tell_object(me,"结果什么也没有。\n"NOR);
            else   
             {
             if(present(ob->query("id"),me))
              { destruct(ob);
                if(present("gold card",me))
                  {
                   tell_object(me,"你的金卡加了二百两"HIY+"黄金。\n"NOR);
                    me->add("card_money",2000000);
                  }
                   else
                        { ob=new("/d/liwu/obj/goldcard");
                          ob->move(me);
                          tell_object(me,"发现了一张"+HIY"金卡"NOR+"。\n"NOR);
       			  me->add("card_money",2000000);		               
                        }  
              }
               else
                 {
                    tell_object(me,"你发现有一"+ob->query("unit")+ob->query("name")+"。\n"NOR);
          if(ob->query("id")=="haba gou")
          {
                    ob->set("boss_id",me->query("id"));
		  ob->set("name",me->name(1)+"的哈巴狗");
                  ob->set("mud_age",200000);
                  ob->set("gender","雄性");
                  ob->set_leader(me);
                  ob->move(environment(me));
                  }
                 else  ob->move(me);
                 }
             }
        
      }
      else 
      {
      if(present("gold card",me))
                 {
                   tell_object(me,"你的金卡加了二百两"HIY+"黄金"NOR+"。\n"NOR);
                   me->add("card_money",2000000);
                 }

                   else
                        { ob=new("/d/liwu/obj/goldcard");
                          ob->move(me);
                          tell_object(me,"发现了一张"+HIY"金卡"NOR+"。\n"NOR);
                          me->add("card_money",2000000);                                
                        }  
      } 
         return 1;
  }  

  
