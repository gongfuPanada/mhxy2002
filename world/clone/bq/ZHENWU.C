//yitianjian.c
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIY "���佣" NOR, ({ "zhenwu jian","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 0);
        	set("no_drop", "1");
        	set("no_get", "1");
                        set("no_sell", "1");
                         set("no_give", "1");
                          set("no_put", "1");
                          set("material", "iron");
        	set("long", "����һ���������е�������ֻ�����������ͣ�����ӵ����ѱ�����\n");
        	set("wield_msg","$N�͵ذγ�$n����˳���ڿ��ж��˸�������\n");
        	set("unwield_msg", "$N���е�$nͻȻ�ڿ��л��˵����磬���佣��֮��ؽ����С�\n");
	}
    	init_sword(200);
	setup();
}