//By tianlin@mhxy for 2002.2.25

#include <ansi.h>
#include <login.h>

inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
       set_name("冥王", ({ "ming wang", "wang", "mingwang" }));

       set("long","地藏菩萨师弟,不满地藏崇尚佛学,长期居于酆都城外.\n");
       set("attitude", "peaceful");
	set("per", 30);
	set("str", 35);
	set("int", 25);
       set("age", 30);
	set("title", HIB"阴曹地府"NOR);
	set("nickname", HBRED+HIY"冥界之神"NOR);
       set("nkgain",790);
       set("max_kee", 3000);
       set("max_gin", 2500);
       set("max_sen", 2000);

       set("force", 7500);
       set("max_force", 4200);
       set("force_factor", 200);
       set("max_mana", 4500);
       set("mana", 8000);
       set("mana_factor", 200);

       set("combat_exp", 5000000);
       set("daoxing", 6000000);

       set_skill("stick", 285);
       set_skill("kusang-bang", 285);
       set_skill("unarmed", 285);
       set_skill("whip", 285);
       set_skill("hellfire-whip", 285);
       set_skill("dodge", 285);
       set_skill("parry", 285);
       set_skill("literate", 180);
       set_skill("spells", 285);
       set_skill("force", 285);
       set_skill("tonsillit", 285);
       set_skill("ghost-steps", 285);
       set_skill("gouhunshu", 285);
       set_skill("jinghun-zhang", 285);
       set_skill("zhuihun-sword", 285);
       set_skill("sword", 285);

	map_skill("stick","kusang-bang");
	map_skill("parry", "kusang-bang");
	map_skill("spells", "gouhunshu");
	map_skill("dodge", "ghost-steps");
	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
       set("chat_chance_combat", 40);
       set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "sheqi" :),
                (: cast_spell, "gouhun" :),
       }) );


       set("nkgain", 400);

	set_temp("apply/dodge", 150);
	set_temp("apply/armor", 150);


create_family("阎罗地府", 1, "你好");

       setup();
	carry_object("/d/obj/weapon/stick/wuchangbang")->wield();
	carry_object("/d/obj/cloth/taijicloth")->wear();
}


void attempt_apprentice(object ob)
{
		int size = sizeof(obstacles);
  	string *names = keys(obstacles);
  	int i;
  	for (i = 0; i < size; i++)
      	if (ob->query("obstacle/"+names[i])!="done" && !wizardp(ob))
      	{
 	   command("shake");
    	   command("say 这位" + RANK_D->query_respect(ob) + "尚未历尽西行难关，恐怕难以领悟高深武学。\n");
	   return;
      	}
        command("grin");
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
	//me->set("class", "youling");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
              ob->set("class", "youling");
		ob->set("title", HIB"阴曹地府"NOR+HBBLU+HIR"冥王座下弟子"NOR);
}


�
