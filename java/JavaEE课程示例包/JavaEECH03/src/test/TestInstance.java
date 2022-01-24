package test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import instance.BeanClass;
public class TestInstance {
	public static void main(String[] args) {
		//��ʼ��Spring����ApplicationContext�����������ļ�
		ApplicationContext appCon = new ClassPathXmlApplicationContext("applicationContext.xml");
		//���Թ��췽��ʵ����Bean
		BeanClass b1 = (BeanClass)appCon.getBean("constructorInstance");
		System.out.println(b1+b1.message);
		BeanClass b2 = (BeanClass)appCon.getBean("staticFactoryInstance");
		System.out.println(b2+b2.message);
		BeanClass b3 = (BeanClass)appCon.getBean("instanceFactoryInstance");
		System.out.println(b3+b3.message);
		
	}
}
