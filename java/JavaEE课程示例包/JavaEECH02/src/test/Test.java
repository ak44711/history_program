package test;
import org.springframework.beans.factory.BeanFactory;
import org.springframework.beans.factory.xml.XmlBeanFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;
import org.springframework.core.io.FileSystemResource;

import dao.TestDao;

public class Test {

	//Spring IoC�����������Ҫ�ǻ���BeanFactory��ApplicationContext�����ӿڡ�
	//����BeanFactoryʵ��ʱ����Ҫ�ṩXML�ļ��ľ���·����
	//���磬���Խ���һ��ch1Ӧ����main�����Ĵ����޸����£�
	/*public static void main(String[] args) {
		// TODO Auto-generated method stub
		BeanFactory beanFac = new XmlBeanFactory(
				new FileSystemResource("D:\\EclipseWorkSpace\\JavaEECH02\\src\\applicationContext.xml")
				);
						//ͨ��������ȡtestʵ��
						TestDao tt = (TestDao)beanFac.getBean("test");
						tt.sayHello();


	}*/
	//����ApplicationContext�ӿ�ʵ��ͨ�������ַ�����
	//1��ͨ��ClassPathXmlApplicationContext���������һ�µ�ʵ����ʾ
	/*public static void main(String[] args) {
		//��ʼ��Spring����ApplicationContext�����������ļ�
		ApplicationContext appCon = new ClassPathXmlApplicationContext("applicationContext.xml");
		//ͨ��������ȡtestʵ��
		TestDao tt = (TestDao)appCon.getBean("test");
		tt.sayHello();
	} */
	
	//2��ͨ��FileSystemXmlApplicationContext����
	public static void main(String[] args) {
		//��ʼ��Spring����ApplicationContext�����������ļ�
				ApplicationContext appCon = 
		new FileSystemXmlApplicationContext("D:\\EclipseWorkSpace\\JavaEECH02\\src\\applicationContext.xml");
				//ͨ��������ȡtestʵ��
				TestDao tt = (TestDao)appCon.getBean("test");
				tt.sayHello();
	}
	//3��ͨ��Web������ʵ����ApplicationContext����
	//��WebӦ����ʹ�ã������γ��н���


}
