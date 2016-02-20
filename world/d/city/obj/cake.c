// by night
// by xiaoran

#include <ansi.h>
#include <command.h>

inherit ITEM; 

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������ڵ��ϾͲ��ܳ��ˣ�\n");
    set("no_give","�������յ��Ⱑ����ô���������أ�\n");
    set("no_drop","���յ������˶��ϧѽ��\n");
    set("no_sell","���Ƕ����ģ��������ˡ�\n");
  }
  add_action("do_eat", "eat"); 
  add_action("do_wish", "wish");}

void create()
{
  set_name( HIY "���յ���" NOR , ({"cake", "dangao"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ��߼����͵��⣬�����м����֣�\n\n"
HIR"                  ף�����տ���\n"NOR);
    set("value", 10000);
    set("no_beg",1);
    set("no_get",1);
    set("no_give",1);
    set("no_steal",1);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me, ob;
  int vkar,gain;
   me = this_player(); 
   vkar=(int)me->query("kar");
  if (arg!="cake" && arg!="dangao")
            return notify_fail("�����ʲô��\n");

  if ( me->query("fired") )
  {
  if ( me->query("wished") )
      {   
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity()); 

  message_vision(HIG "$N�������ڵذѵ��������ȥ�����˸����á�\n\n" NOR, me);  
  message_vision(HIG "$N��Ը��ʵ������\n" NOR, me);  
    me->set("fired",0);
       if ( me->query_temp("marks/per") ){ 
       me->add("per",1);
       me->set("wished",0);
       me->set_temp("marks/per",0); 
    destruct(this_object());
    return 1;
         }
      if ( me->query_temp("marks/force") ){ 
    me->add("max_force",10);
    me->add("maximum_force",10);
    me->set("wished",0);
    me->set_temp("marks/force",0); 
    destruct(this_object());
    return 1;
         }
      if ( me->query_temp("marks/mana") ){
    me->add("max_mana",1);
    me->add("maximum_mana",1);
    me->set("wished",0);
    me->set_temp("marks/mana",0); 
    destruct(this_object());
    return 1;
        } 
         if ( me->query_temp("marks/exp") ){
    me->add("combat_exp",3000);    
    me->set("wished",0);
    me->set_temp("marks/exp",0); 
    destruct(this_object());
    return 1;
        } 
         if ( me->query_temp("marks/daoxing") ){
    me->add("daoxing",4000);
    me->set("wished",0);
    me->set_temp("marks/daoxing",0); 
    destruct(this_object());
    return 1;
          } 
      if ( me->query_temp("marks/pot") ){ 
    me->add("potential",3000);
    me->set("wished",0);
    me->set_temp("marks/pot",0); 
    destruct(this_object());
    return 1;
          } 
    return 1;
       } 
  tell_object(me,"�Ե���ǰ������Ը(wish)�ɡ�\n"
"������ԸҪ����(force).����(mana).��ѧ(exp).����(daoxing).Ǳ��(pot).��ò(per)��\n");
       return 1;
   } 
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity()); 
  me->add("combat_exp",vkar*10); 
  message_vision(HIG "$N���̻��ʵذѵ��������ȥ������δ����Ĩ��Ĩ�졣\n" NOR, me);   
    destruct(this_object());
  return 1;
}
 
int do_wish(string arg) 
{
    object me;
    me = this_player();

  if (arg=="force") { 
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
    me->set("wished",1);
    me->set_temp("marks/force",1);
    return 1;
    }  
  if (arg=="mana") { 
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
    me->set("wished",1); 
    me->set_temp("marks/mana",1);
    return 1;
    } 
  if (arg=="exp") {
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
    me->set("wished",1);
    me->set_temp("marks/exp",1);
    return 1;
    } 
  if (arg=="daoxing") {
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
    me->set("wished",1);
    me->set_temp("marks/daoxing",1);
    return 1;
    } 
 if (arg=="pot") {
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
    me->set("wished",1);
    me->set_temp("marks/pot",1);
    return 1;
    } 
 if (arg=="per") {
  message_vision(HIY "$N�����۾���ĬĬ�����˸�Ը��\n" NOR, me);  
    me->set("wished",1);
    me->set_temp("marks/per",1);
    return 1;
    } 
  return notify_fail("������ʲôԸ��������ԸҪ����(force).����(mana).��ѧ(exp).����(daoxing).Ǳ��(pot).��ò(per)��\n"); 
}

void owner_is_killed()
{
        object me = this_player();
        write(HIM"ֻ��һ����������...ʬ����ʲô������ʧ�ˡ�\n"NOR);
        destruct(this_object());
        return;
}