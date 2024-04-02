package com.spring.controller;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class ArduinoController {
	String arduinoIP = "";
	@GetMapping("/rc/control")
	public String form() {
		String url = "/arduinoForm";

		return url;
	}
	
	@RequestMapping(value="/rc/ip_set", method=RequestMethod.POST)
	@ResponseBody
	public void ip_set(HttpServletRequest request) {
		String ip_one = request.getParameter("ip_one");
		String ip_two = request.getParameter("ip_two");
		String ip_three = request.getParameter("ip_three");
		String ip_four = request.getParameter("ip_four");
		String ip = ip_one+"."+ip_two+"."+ip_three+"."+ip_four;
		System.out.println("ip==========="+ip);
		arduinoIP = ip;
		
	}

	@GetMapping("/motor/{direct}")
	@ResponseBody
	public String motor(@PathVariable("direct") String direct) {
		String result="";
		System.out.println(direct);
		String url = "/motor/"+direct;
		String method ="GET";
		
		HttpURLConnection conn = getHttpURLConnection(url,method);

		result = getHttpRespons(conn);
		
		return result;
	}
	
	@GetMapping("/led/built_in/{num}")
	@ResponseBody
	public String built_in(@PathVariable int num) {
		String result = "";
		
		System.out.println(num);
		String url = "/led/built_in/"+num;
		String method = "GET";
		HttpURLConnection conn = getHttpURLConnection(url,method);

		result = getHttpRespons(conn);
		 
		return result;
	}

	public HttpURLConnection getHttpURLConnection(String target_url, String method) {
		HttpURLConnection conn = null;
		URL url = null;
		
		try {

			url = new URL("http://" + arduinoIP+target_url);
			conn = (HttpURLConnection) url.openConnection();
			conn.setRequestMethod(method); // Method 방식 설정.
			conn.setConnectTimeout(5000);
			conn.setRequestProperty("Content-Type", "text/html;charset=UTF-8");

		} catch (MalformedURLException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

		return conn;
	}

	private String getHttpRespons(HttpURLConnection conn) {
		String result = null;

		try {
			if (conn.getResponseCode() == 200) { // 정상적으로 데이터를 받았을 경우
				result = "http 200 OK";
			} else { // 에러 응답인경우
				result = conn.getResponseCode()+"\n";
				result += conn.getResponseMessage();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			conn.disconnect(); //연결 해제
		}
		
		return result;
	}
}
