package interceptor;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

public class TestInterceptor implements HandlerInterceptor{
	@Override
	public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler)
			throws Exception {
		System.out.println("preHandler�����ڿ������Ĵ������󷽷�ǰִ��");
		/**
		 * ����true��ʾ��������ִ�У�����false��ʾ�жϺ�������
		 */
		return true;
	}
	
	@Override
	public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler,
			ModelAndView modelAndView)
			throws Exception {
		System.out.println("postHandler�����ڿ������Ĵ������󷽷�֮�󣬽�����ͼ֮ǰִ��");
	}
	
	@Override
	public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler,
			Exception ex)
			throws Exception {
		System.out.println("afterCompletion�����ڿ������Ĵ������󷽷�ִ����ɺ󣬼���ͼ��Ⱦ֮��ִ��");
	}
}
