//а����ɱ������, dragonshoot.c
//created by foc,19-6-01
//˵��������ԭ���Ķ�Ӧ��֪�����������ɣ�

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
       int myexp, yourexp, mydx, yourdx, myskill, yourskill;
       int chance, myto, yourto, success, damage, skill;
       skill=(int)me->query_skill("evileye",1);
damage=(int)me->query_skill("evilfight",1)+(int)me->query_skill("force",1)+(int)me->query_skill("unarmed",1)+(int)me->query_skill("evilfight",1);       
       if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      target->is_corpse())
       return notify_fail("��Ҫ�ú������ɵ�˭��\n");
       if( target==me ) return notify_fail("���������������ַ�ʽʩ�ӵ��Լ����ϡ�\n");
       if(me->query_temp("dragonshoot_busy"))
       return notify_fail("���������û�м��е��㹻�ĳ̶ȣ��޷��ٴ�ʹ�ú�������\n");
       if( (int)me->query_skill("evileye", 1 ) < 120 )
       return notify_fail("�������ڵ�а������Ϊû�취�ٻ�������\n");
       if( (int)me->query_skill("evilfight", 1 ) < 120 )
       return notify_fail("�������ڵ���ɱȭ��Ϊû�취���ݺ�����\n");
       if( (int)me->query("combat_exp") < 1200000 )
       return notify_fail("����Ц���������ս�����飬���ѽ��\n");
       if( (int)me->query("daoxing") < 500000 )
       return notify_fail("����Ц�����������У�����Ҽ�ѽ��\n");
       if( (int)me->query("max_force") < 1200 || (int)me->query("force") < 1200 )
       return notify_fail("ʹ�ú�������Ҫ�����ų�ǿ����������������������\n");
       if( (int)me->query("max_mana") < 600 || (int)me->query("mana") < 200 )
       return notify_fail("ʹ�ú�������Ҫһ���ķ�������ķ���������\n");
       if( (int)me->query("kee") < 300 || (int)me->query("sen") < 300 )
       return notify_fail("�����ڵ�����״�����ѣ��������ˡ�\n");
       if (me->query_skill_mapped("force")!="evileye")
       return notify_fail("�����ʹ��а�������ٻ�������\n");
       else
{
       message_vision(HIC "$Nͷ�ϵ�а�۷ų�ǿ�ҵĹ�â������$N�Ļ���ȼ���ɫ�Ļ��档\n���ܶ�ʱ��������һ�����ȣ�\n" NOR,me);
       message_vision(HIR"�����Ļ����$N�����ϱ���������Ĵ����ӡ�\n"NOR,me);
       if( (int)me->query_skill("evileye", 1) < (int)target->query_skill("segokee", 1)*3)
{
       message_vision(HIY "$n��ȫ���ų����ɫ��ʥ������$N�ķų��Ļ��汻��ȫ��ס��û�в����κ����ã�\n" NOR,me,target);
       me->start_busy(3);
       tell_object (me, "��������Ķ��ֺ�ǿ������������\n");
       tell_object (target, "��Ķ��ּ����������������Ŀ�ɿڴ���\n");
       target->add("force",-50);
       target->kill_ob(me);
       me->kill_ob(target);
       return notify_fail("���������û��ǿ�󵽿��Թᴩʥ�����ĳ̶ȡ�\n");
}
       if( random((int)me->query_skill("evileye",1)) < random((int)target->query_skill("evileye",1)/2))
{
       message_vision(HIC "$nͷ�ϵ�а�۷ų�ҫ�۵Ĺ�â��$N�ķų��Ļ���ֻ��Χ����$n��������ת��û�в����κ����ã�\n" NOR,me,target);
       me->start_busy(3);
       tell_object (me, "��������Ķ���Ҳ��а�������´�Ҳ���ܳɹ���\n");       
       tell_object (target, "��Ķ��ּ���Ҳ��а��������������һ����\n");
       target->add("force",-50);
       target->kill_ob(me);
       me->kill_ob(target);
       return notify_fail("Ϊ�˽���������㽫�����ջ����ڡ�\n");
}
       else
{
       target->receive_damage("kee",damage/5);
       target->receive_damage("sen",damage/5);
       me->add("force",-100);
       if( (int)target->query("combat_exp")+(int)target->query("daoxing") < (int)me->query("combat_exp")/3+(int)me->query("daoxing")/3 && !target->is_corpse() && !target->is_ghost())
{
       target->receive_wound("kee",damage/20);
       target->receive_wound("sen",damage/20);
       me->start_busy(5);
       message_vision(HIM "���$n���̱�����������죬�ҽ������ϴӿ��д�����\n" NOR,me,target);
       COMBAT_D->report_status(target, 0);
       me->kill_ob(target);
       tell_object (me,"��������Ŀǰ̫���ˣ�û��Ҫ����ôǿ����ʽ��\n");
       tell_object (target,"��Ȼ����̫���ˣ��������ɡ�\n");
       target->start_busy(random(4));
       target->kill_ob(me);
}
       else
{       
       message_vision(HIC "$N���ϵ�����Խ��Խǿ�ˡ�ͻȻ�����еĻ��漯����$N�������ϣ��γ���\nһ����������οռ䡣����ֻ����$N���һ���������У�а����ɱ����������\nһͷ�޴�Ļ����γɵĺ�������һ�����������οռ��ﱼӿ���������Ŵ��쳯\n��$nֱ�ɹ�ȥ���ƺ�Ҫ��$n�����̵���\n" NOR,me,target);
       target->kill_ob(me);
       me->kill_ob(target);
       if( random((int)me->query_skill("evileye", 1)) < random((int)target->query_skill("segokee", 1)*4) && (int)target->query_skill("segokee",1) > 0)
{
       message_vision(HIY "$n��ȫ���ų����ɫ��ʥ����������������ȫ��ס��û�в����κ����ã�\n" NOR,me,target);
       me->start_busy(3);
       tell_object (me, "��������Ķ��ֺ�ǿ������������\n");
       tell_object (target, "��Ķ��ּ����������������Ŀ�ɿڴ���\n");
       target->add("force",-100);
       return notify_fail("���������û��ǿ�󵽿��Թᴩʥ�����ĳ̶ȡ�\n");
}
       if( random((int)me->query_skill("evileye", 1)) < random((int)target->query_skill("evileye", 1)/2) && (int)target->query_skill("evileye",1) >0 )
{
       message_vision(HIC "$nͷ�ϵ�а��ͻȻ�ų���â������$nһ����Ц��$N�ٻ�����\n�ĺ�����Ȼ��$n�������һ��ͬ�������οռ����˽�ȥ��\n" NOR,me,target);
       target->add("force",-100);
       target->start_busy(1);
       tell_object (me, "��ĺ�������ʧ�ˣ���������Ҳ��а������\n");
       tell_object (target, "�������ֺ���������������ڸϿ칥���ɣ�\n");
       me->start_busy(4);
       return notify_fail("�����ڵ�����һʱû�����У������æ���ҡ�\n");
}
       if( (int)me->query_skill("evileye", 1) <  random((int)target->query_skill("force",1)/3+(int)target->query("max_force")/200 ))
{
       message_vision(HIC "����$n����ȫ����������$N�ٻ������ĺ���һȭ��ɢ�ˡ�\n" NOR,me,target);
       me->start_busy(4);
       tell_object (me, "������������״̬�������´���Ҳ����û��ô�����ˡ�\n");
       tell_object (target, "��˵���ɢ�˺����������������ȴ���۵�������\n");
       target->start_busy(1);
       target->receive_damage("kee",damage/6);
       target->add("force", -200);
       return notify_fail("�����ڵ�����һʱû�����У������æ���ҡ�\n");
}
       else
{ 
       myexp = (int)me->query("combat_exp");
       yourexp = (int)target->query("combat_exp");
       mydx = (int)me->query("daoxing");
       yourdx = (int)target->query("daoxing");
       myskill = (int)me->query_skill("evilfight", 1)+(int)me->query_skill("evileye", 1)+(int)me->query_skill("force", 1)+(int)me->query_skill("dodge", 1)+(int)me->query_skill("unarmed", 1);
       yourskill = (int)target->query_skill("force",  1)*2+(int)target->query_skill("dodge", 1)*2+(int)target->query_skill("parry", 1)*2;
       myto=mydx+myexp+myskill;
       yourto=yourexp+yourdx+yourskill;
       chance =(myto/yourto)*100-10;
       if( chance >= 10) success=1;
       if( chance < 10) success=0;
       if( success=1)
{
       if( chance >=90 || chance=100 )
{
       message_vision(HIR "���$n������������$N�ٻ������ĺ������˽�ȥ��ֻ����$n�ҽ���һ������֫���̾ͻ�Ϊ�˻ҽ���\n" NOR,me,target);
       target->set("kee",-20000);
       target->set("sen",-20000);
       target->start_busy(2);
       COMBAT_D->report_status(target, 0);
       message("channel:rumor", HIM + "�����α����顿ŷ��ɣA����˵"+
       target->query("name")+"��"+me->query("name")+"��а����ɱȭ����ǿ��������ˣ�\n"NOR,users());
}
       if( chance >=70 && chance < 90)
{
       message_vision(HIR "$n��æƴ��ȫ�����ֵ�ס$N�ٻ������ĺ�����ֻ��$n��˫�����̾�̿���ˡ�\n���������$n���Ǳ�������ס���������أ�\n" NOR,me,target);
       target->receive_wound("kee", damage/10);
       target->receive_wound("sen", damage/10);
       target->receive_damage("kee", damage/4);
       target->receive_damage("sen", damage/4);
       COMBAT_D->report_status(target, 0);       me->start_busy(4+random((int)me->query_skill("evileye",1)/50));
}
       if( chance >=40 && chance < 70)
{
       message_vision(HIR "$n����ȫ�������������ڽ����������ˣ������������˲��ᣡ" NOR,me,target);
       target->receive_wound("kee",damage/20);
       target->receive_wound("sen",damage/20);
       target->receive_damage("kee", damage/3);
       target->receive_damage("sen", damage/3);
       COMBAT_D->report_status(target, 0);
       target->start_busy(random(2));
       me->start_busy(2+random(2));
}
       if( chance >=20 && chance < 40 )
{
       message_vision(HIR "$n��æ��һ��һ��������Ȼ����������һ�£�����Щ���ˡ�\n" NOR,me,target);
       target->receive_wound("kee", damage/30);
       target->reveive_wound("sen", damage/30);
       target->receive_damage("sen", damage/5);
       target->receive_damage("kee", damage/5);
       COMBAT_D->report_status(target, 0);
       target->start_busy(1);
       me->start_busy(3);
}
      if( chance <20 )
{
      message_vision(HIG "����$nʩչ�Ṧ�����׶��˿�ȥ��ֻ���յ���һ��Ƥ��\n" NOR,me,target);
      target->receive_damage("kee",100);
      target->receive_damage("sen",100);
      COMBAT_D->report_status(target, 0);
      me->start_busy(2);
}
}
      if( success=0 )
{
      message_vision(HIG "����$n����һ������ȫ�����$N�ٻ������ĺ����Ĺ�����\n" NOR,me,target);
      message_vision(GRN "$n��$N��Ȼ���ɶ������ô�����Ĺ������������һ������æ���ң�\n" NOR,me,target);
      target->start_busy(1);
      me->start_busy(3);
}       
       me->receive_damage("kee",200);
       me->receive_damage("sen",200);
       me->add("force", -1000);
       me->add("mana", -200);
       message_vision(HIG "$N�ٻ������ĺ�����Хһ�����ƿն�ȥ��\n" NOR,me);
       message_vision(RED "$N���ź����ڿ�����ʧ������һ��������ʼ�����ظ��Լ���������\n" NOR,me);
       tell_object (me, "��е�ʹ���˺�������������Щ��֧��\n");
       COMBAT_D->report_status(me, 0);
}
                        }
               }
         }
       me->set_temp("dragonshoot_busy",1);
       call_out("remove_effect",100+random(5),me);

       return 1;
}
void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("dragonshoot_busy");
  message_vision(HIW "$N�����ϵ������ٶȳ��֣�������$N�ֿ����ú������ˡ�\n" NOR,me);
}