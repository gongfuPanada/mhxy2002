#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIY"С���"NOR, ({"jinbi", "jinbi_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "jinbi");
               set("long", HIY"һö���μǵ�Ӳ�ң��������ȫ����ʦ��ȫ�Ҹ���\n"NOR);
                set("unit", "��");
               set("base_value", 1000000);
                set("base_unit", "ö");
		set("base_weight", 3);
	}
	set_amount(1);
}
