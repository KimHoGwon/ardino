//package com.spring.controller;
//
//import java.io.IOException;
//import java.net.HttpURLConnection;
//import java.net.MalformedURLException;
//import java.net.URL;
//
//import javax.servlet.http.HttpServletRequest;
//
//import org.springframework.stereotype.Controller;
//import org.springframework.web.bind.annotation.GetMapping;
//import org.springframework.web.bind.annotation.PathVariable;
//import org.springframework.web.bind.annotation.RequestMapping;
//import org.springframework.web.bind.annotation.RequestMethod;
//import org.springframework.web.bind.annotation.ResponseBody;
//
//@Controller
//public class ArduinoController2 {
//	public String arduinoIP = "";
//	
//	@GetMapping("/rc/form")
//	public String form() {
//		String url="/arduinoForm";
//		
//		return url;
//	}
//	
//	@RequestMapping(value="/rc/ip_set", method=RequestMethod.POST)
//	@ResponseBody
//	public void ip_set(HttpServletRequest request) {
//		String ip_one = request.getParameter("ip_one");
//		String ip_two = request.getParameter("ip_two");
//		String ip_three = request.getParameter("ip_three");
//		String ip_four = request.getParameter("ip_four");
//		String ip = ip_one+"."+ip_two+"."+ip_three+"."+ip_four;
//		System.out.println("ip==========="+ip);
//		arduinoIP = ip;
//		
//	}
//	
//	@GetMapping("/rc/built_in/{num}")
//	@ResponseBody
//	public String built_in(@PathVariable int num) {
//		System.out.println(num);
//		String result = "";
//		HttpURLConnection conn = getHttpURLConnection(num);
//		result = getHttpRespons(conn);
//		return result;
//	}
//	
//	@GetMapping("/rc/move/{move}")
//	@ResponseBody
//	public String move_built_in(@PathVariable String move) {
//		String result = "";
//		HttpURLConnection conn = MgetHttpURLConnection(move);
//		result = getHttpRespons(conn);
//		return result;
//	}
//	
//	public HttpURLConnection getHttpURLConnection(int num) {
//		HttpURLConnection conn=null;
//		URL url = null;
//		
//		try {
//			url = new URL("http://" + arduinoIP + "/rc/built_in/" + num);
//			System.out.println(url);
//			conn = (HttpURLConnection)url.openConnection();
//			conn.setRequestMethod("GET");
//			conn.setConnectTimeout(5000);
//			conn.setRequestProperty("Content-Type", "text/html;charset=UTF-8");
//		}catch(MalformedURLException e) {
//			e.printStackTrace();
//		}catch(IOException e) {
//			e.printStackTrace();
//		}
//		
//		
//		return conn;
//	}
//	
//	public HttpURLConnection MgetHttpURLConnection(String move) {
//		HttpURLConnection conn=null;
//		URL url = null;
//	
//		try {
//			url = new URL("http://" + arduinoIP + "/rc/move/" + move);
//			System.out.println(url);
//			conn = (HttpURLConnection)url.openConnection();
//			conn.setRequestMethod("GET");
//			conn.setConnectTimeout(5000);
//			conn.setRequestProperty("Content-Type", "text/html;charset=UTF-8");
//		}catch(MalformedURLException e) {
//			e.printStackTrace();
//		}catch(IOException e) {
//			e.printStackTrace();
//		}
//		
//		
//		return conn;
//	}
//	
//	private String getHttpRespons(HttpURLConnection conn) {
//		String result = null;
//		
//		try {
//			if(conn.getResponseCode() == 200) {
//				result = "200 OK";
//			}else {
//				result = conn.getResponseCode()+"\n";
//				result += conn.getResponseMessage();
//			}
//		}catch(IOException e) {
//			e.printStackTrace();
//		}finally {
//			conn.disconnect();
//		}
//		return result;
//	}
//}
