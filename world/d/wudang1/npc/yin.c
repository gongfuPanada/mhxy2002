//[4;53m[1;31mBy tianlin@mhxy and elva@mhxy for 2001.9.27[2;37;0m
//部分优化

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("殷梨亭", ({ "yin liting","yin"}));
        set("nickname", HIW"武当"NOR+HIR"六侠"NOR);
        set("long",
                "他就是张三丰的最软弱的弟子、武当七侠之六的殷梨亭。\n"
                "身穿一件干干净净的青布长衫。\n"
                "他不过二十出头年纪，精明能干，嫉恶如仇，性如烈火，却一直一副不愉快的表情。\n");
        set("gender", "男性");
        set("age", 23);
        set("attitude", "peaceful");
        set("class", "wudang");
        set("shen_type", 1);
        set("str", 26);
        set("int", 39);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 5000);
        set("max_force", 1000);
        set("mana", 5000);
        set("max_mana", 1000);
       set("force_factor", 50);
       set("mana_factor", 40);
        set("combat_exp", 1250000);
        set("daoxing", 1000000);

        set_skill("force", 195);
        set_skill("wudang-force", 200);
        set_skill("spells", 195);
        set_skill("wudang-xianfa", 170);
        set_skill("dodge", 195);
        set_skill("tiyunzong", 190);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 160);
        set_skill("parry", 180);
        set_skill("sword", 180);
        set_skill("liangyi-jian", 200);
        set_skill("literate", 125);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 100000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应在道德及武功方面多下努力，来日方长吗！");
                return;
        }
        if ((int)ob->query_skill("wudang-force", 1) < 140) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +
		"我辈中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33m武当派[1;37m第[1;36m三[1;37m代弟子[2;37;0m");
}

