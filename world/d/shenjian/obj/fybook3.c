// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("风云志", ({ "fybook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long", "一本神秘的古书，书页已经翻黄了！你可以好好看看(kan)。\n");
		set("value", 0);
		set("material", "paper");
				
	}
}

void init()
{
   add_action("do_kan","kan");
}

int do_kan(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "fybook") {
      tell_object(me, "你要看什么？\n");
      return 1;
   }
   tell_object(me, "一座高山，一处低岩，一道新泉，一株古松，一炉红火，一壶绿茶，一位老人，一个少年。

　　“天下最可怕的武器是什么？”少年问老人：“是不是例不虚发的小李飞刀？”

　　“以前也许是，现在却不是了。”

　　“为什么？”

　　“因为自从小李探花隐去后，这种武器已成绝晌。”老人黯然叹息：“从今以后，
世上再也不会有小李探花这种人，也不会再有小李飞刀这种武器了。”

　　少年仰望高山，山巅白云悠悠。

　　“现在世上最可怕的武器是什么？”少年又问老人：“是不是蓝大先生的蓝山古剑？”

　　“不是。”

　　“是不是南海神力王的大铁椎？”

　　“不是。”

　　“是不是关东落日马场冯大总管的白银枪？”

　　“不是。”

　　“是不是三年前在邯郸古道上，轻骑诛八寇的飞星引月刀？”

　　“不是。”

　　“我想起来了。”少年说得极有把握：“是杨铮的离别钩，一定是杨铮的离别钩。”

　　“也不是，”老人道：“你说的这些武器虽然都很可怕，却不是最可怕的一种。”

　　“最可怕的一种是什么？”

　　“是一口箱子。”

　　“一口箱子？”少年惊奇极了：“当今天下最可怕的武器是一口箱子？”

　　“是的。”
\n");
   return 1;
}
