// modified by vikee for xlqy
// 2000-11-26 16:05


#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{	
        int strength,howlong,str;
	object weapon=me->query_temp("weapon");
      	mapping action;        
	
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if( (int)me->query_str() < 20 )
                return notify_fail("�����̫��, �޷�ʹ�á������������\n");   
      if (!target->is_fighting(me))
             return notify_fail("����û���ڴ�ܣ�\n");
      if ((int)me->query_skill("force",1)<60)
          return notify_fail("����ڹ�̫�\n");
      if ((int)me->query_skill("dali-bang",1)<60)
         return notify_fail("�����������򲻹���\n");
      if (me->query("force")<500)
           return notify_fail("���������̣����Գ��С�\n");
      if (me->query_temp("pfm_shenli")) return notify_fail("���Ѿ������������ˡ�\n");
	me->add("force",-100);
	message_vision(HIW"$NͻȻ��������"NOR+weapon->name()+
	HIW"����ߺ�һ�������������!\n"NOR,me,target);
	me->add("sen",-100);

        howlong=me->query_skill("dali-bang")/2;

	//  strength=me->query_temp("apply/strength");
	me->add_temp("apply/strength",me->query_skill("dali-bang",1)/2);
	call_out("remove_ansi",howlong,me,str);
	me->set_temp("pfm_shenli",1);
    	me->set("actions",action);
    	me->reset_action();
	return 1;
}


int remove_ansi(object me,int strength)
{	object here;
	me->add_temp("apply/strength",-me->query_skill("dali-bang",1)/2);
	me->delete_temp("pfm_shenli");
	message_vision(HIW"$N���������������뿪��\n"NOR,me);
	return 1;	
}