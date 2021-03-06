//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <obstacle.h>

void create()
{
	set_name("吕岳", ({ "lu yue", "luyue", "lu" ,"monster"}));
	set("title", HIY"瘟癀之昊天大帝"NOR);   
	set("long", @LONG
吕岳原为九龙岛炼气士。后拜入碧游宫通天教主座下，万仙阵之后，
被封为瘟癀之昊天大帝之职，率领瘟部六位正神。
LONG);
	set("gender", "男性");
	set("age", 20);
	set("attitude", "heroism");
	set("per", 9);
	set("max_kee", 1850);
	set("max_gin", 1800);
	set("max_sen", 1850);
	set("force", 8000);
	set("max_force", 5000);
	set("force_factor", 150);
	set("max_mana", 2600);
	set("mana", 4300);
	set("mana_factor", 100);
	set("combat_exp", 2500000);
	set("daoxing", 4500000);

  set_skill("unarmed", 285);
  set_skill("dodge", 285);
  set_skill("parry", 285);
  set_skill("spells", 285);
  set_skill("yaofa", 285);
  set_skill("sword",285);
  set_skill("qixiu-jian",285);
  set_skill("blade", 285);
  set_skill("kugu-blade", 285);
  set_skill("literate", 180);
  set_skill("lingfu-steps", 285);
  set_skill("yinfeng-zhua", 285);
  set_skill("force", 285);   
  set_skill("huntian-qigong", 285);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
              (: exert_function, "recover" :),
	//	(: cast_spell, "jingang" :),
	}) );
        create_family("陷空山无底洞", 1, "祖师");

	setup();
	carry_object("/d/obj/weapon/blade/yanblade")->wield();
	carry_object("/u/tianlin/obj/goldarmor")->wear();
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
	if ( (string)ob->query("family/family_name")=="陷空山无底洞") {
		command("smile");
		command("say 很好，我就收下你，希望你多加努力，早成正果。\n");

		command("recruit " + ob->query("id") );
        message("channel:rumor",HIM+"【"HIW"谣言"HIM"】某人："BLINK+HIR+ob->query("name")+NOR+HIM"寻找到无底洞祖师"HIY"吕岳大帝"HIM",得到了"HIY"吕岳大帝"HIM"的指点！\n"NOR,users() );
		return;
	}

	command("shake");
	command("say " + "走开走开。\n");
	return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
              ob->set("title",HIR"血饮狂刀"NOR);
}

�
