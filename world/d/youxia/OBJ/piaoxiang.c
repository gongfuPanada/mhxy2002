// xinfa.c	�仨��ѩ     created 17-06-2001 ����Ʈ(piao)


inherit ITEM;
#include <ansi.h>

void create()
{
  set_name(HIW"��Ѫ��Ʈ�㡽"NOR, ({ "piaoxiang", "shu", "book" }));
  set_weight(600);
  if( clonep() )
	set_default_object(__FILE__);
  else {
	set("unit", "��");
       set("no_get", 1);
       set("no_sell", 1);
       set("no_give", 1);
       set("no_put", 1);
	set("long", "����һ�����������͵�һ���书�ؼ���\n");
	set("value", 0);
	set("material", "paper");
	set("skill", ([
		"name":		"piaoxiang",	// name of the skill
		"exp_required":	1000,		// minimum combat experience required
						// to learn this skill.
		"sen_cost":	30,		// gin cost every time study this
		"difficulty":	30,		// the base int to learn this skill
						// modify is gin_cost's (difficulty - int)*5%
		"max_skill":	280,		// the maximum level you can learn
						// from this object.
		]) );
	}
}