//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//部分优化

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("清虚道长", ({ "qingxu daozhang", "qingxu","daozhang" }));
        set("long",
                "他就是宋远桥的弟子清虚道长。\n"
                "他今年三十八岁，主管武当派后山的俗事。\n");
        set("gender", "男性");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);

        set("max_kee", 1000);
        set("max_sen", 800);
        set("force", 1000);
        set("max_force", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 40);
        set("mana_factor", 40);
        set("combat_exp", 60000);
        set("daoxing", 60000);

        set_skill("force", 50);
        set_skill("wudang-force", 50);
        set_skill("spells", 50);
        set_skill("wudang-xianfa", 50);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 40);
        set_skill("unarmed", 60);
        set_skill("taiji-quan", 60);
        set_skill("parry", 50);
        set_skill("sword", 60);
        set_skill("wudang-jian", 40);
        set_skill("taoism", 50);
        set_skill("literate", 50);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");

        create_family("武当派", 3, "弟子");
        set("class", "wudang");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( ((int)ob->query("combat_exp") < 10000)) {
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应在道德及武功方面多下努力，来日方长吗！");
                return;
        }
        command("say 好吧，贫道就收下你了。");
        command("recruit " + ob->query("id"));
}
