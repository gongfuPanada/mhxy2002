inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("�ɲ�-��", ({ "ling", "xiancao", "cao"}));
        set("title", CYN"��Ҷ��ʦ�Ŀ�����ͽ"NOR);   
        set("long", @LONG
����ǰ��������ɽ��һ֧�ɲ�,��֪��ʲô�ط�
��������,�󱻰�Ҷ��ʦ�շ�,��Ϊ�䴫���书��
LONG);
        set("gender", "Ů��");
        set("age", 21);
        set("attitude", "peaceful");
        set("per", 40);
        set("rank_info/self", "��");
        set("rank_info/rude", "�ɲ�");
        set("class", "lingjie");
        set("max_kee", 600);
        set("max_gin", 500);
        set("max_sen", 750);
        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 80);
        set("max_mana", 1500);
        set("mana", 1500);
        set("mana_factor", 100);
        set("combat_exp", 300000);
        set("daoxing", 500000);

        set_skill("literate", 60);
        set_skill("spells", 110);
        set_skill("kongming-spells", 120);
        set_skill("unarmed", 100);
        set_skill("guangming-shouyin", 100);
        set_skill("dodge", 80);
        set_skill("fengtian-steps", 80);
        set_skill("parry", 80);
        set_skill("force", 90);
        set_skill("guangming-force", 80);
        set_skill("umbrella", 80);
        set_skill("lingfan-san",80);

        map_skill("spells", "kongming-spells");
        map_skill("unarmed", "guangming-shouyin");
        map_skill("dodge", "fengtian-steps");
        map_skill("force", "guangming-force");
        map_skill("umbrella", "lingfan-san");

        create_family("���", 3, "����");

        setup();
        carry_object("/d/lingjie/obj/xianlv")->wear();
        carry_object("/d/lingjie/obj/anhun")->wield();
        
}

void attempt_apprentice(object ob,object me)

{
                         command("xf");
                         command("say ֪����!" + RANK_D->query_respect(ob) +
                        "��Ҫ����ѽ,��Ȼ�Ҷ������㡣\n");
                        command("recruit " + ob->query("id") );
      

        return;
        
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "lingjie");
}

void greeting(object me)
{
  if(me->query("family/family_name") == "���")
    return;
 
      command("say �������ȥ�ĵط���?");
      kill_ob(me);
      return;
}

void die()
{
  if (environment())
    command("die");

  set("eff_kee", 600);
  set("eff_gin", 650);
  set("eff_sen", 650);
  set("kee", 600);
  set("gin", 650);
  set("sen", 650);
}

void unconcious()
{
  die ();
}