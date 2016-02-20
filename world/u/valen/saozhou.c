
inherit NPC;

void create()
{
    set_name("扫帚", ({"sao zhou", "sao"}));
  set("under_water",1);

    set("long", "曾经是一头野兽，被雨点点化成了一把大扫帚。\n");
  set("race", "野兽");
  set("age", 10);
  set("age", 30);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "骑");
    set("ride/dodge", 120);
  set_temp("apply/attack", 80);
  set_temp("apply/armor", 80);

  setup();
}

�
