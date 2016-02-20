string clean_tower();
inherit NPC;
void create()
{
       set_name("老者", ({"oldman", "laozhe"}));
       set("gender", "男性");
       set("age", 150);
        set("long", "一位老人家,看上去一副神秘熙熙的样子。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 25);
	set("str", 25);
       set("combat_exp", 1000000);
  set("daoxing", 5000000);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
	set_skill("force", 200);
	set_skill("spells", 200);
        set_skill("sword",300);
	
        set("force", 2000);
        set("max_force", 3000);
        set("force_factor", 100);
        set("max_kee", 1000);
        set("max_sen", 1500);
        set("max_mana", 5000);
        set("mana", 5000);
set("inquiry", ([
"here" : "此地便是灵界了。\n",
"拜师" : (: clean_tower :),
]));

setup();
 
       carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
       carry_object("/d/lingjie/obj/chanyi")->wield();
}

string clean_tower()
{
	object me,obj,env;
	me=this_object();
	obj=this_player();
	env=environment(this_object());

	if( (string)env->query("short")!="灵界入口") {
		command("say " + RANK_D->query_respect(obj) + "你什么意思,我不明白！\n");
		return "嘿嘿。\n";
	}
	if( env->query("exits/enter") ) {
		command("say 好一个"  + RANK_D->query_respect(obj) + "有出息,快请进。\n");
		return "在我们这里,你肯定会出人头地的。 \n";
	}
	command("touchy " + obj->query("id"));
	env->open_down();
	return"别说废话了,快进去吧。\n";
}
�