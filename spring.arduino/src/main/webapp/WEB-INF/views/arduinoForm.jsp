<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>RC CAR</title>
  <!-- Bootstrap CSS -->
  <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
</head>
<body>
  <!-- Header -->
  <div class="container-fluid bg-dark text-center py-4">
    <h1 class="text-light">RC CAR</h1>
  </div>

  <!-- Main Content -->
  <div class="container mt-4">
    <div class="row">
      <!-- Left Section: Image -->
      <div class="col-md-6">
        <img src="C:/Users/30204/Desktop/son.gif" class="img-fluid" alt="RC Car Image">
      </div>
      <div class="col-md-5">
        <div class="card card-primary">
          <div class="card-header">
            <h3 class="card-title">IP Address</h3>&nbsp;&nbsp;
          </div>
          <div class="card-body">
            <form class="row" id="ip_form" name="ip_form">
              <input class="form-control col-md-2" type="text" value="" name="ip_one" id="ip_one">&nbsp;&nbsp;
              <input class="form-control col-md-2" type="text" name="ip_two" id="ip_two">&nbsp;&nbsp;
              <input class="form-control col-md-2" type="text" name="ip_three" id="ip_three">&nbsp;&nbsp;
              <input class="form-control col-md-2" type="text" name="ip_four" id="ip_four">&nbsp;&nbsp;
              <input type="button" class="btn btn-danger" value="입력" onclick="ipInput();"/>
            </form>
          </div>
        </div>
        
        <!-- Right Section: Controls -->
        <div class="card card-primary">
          <div class="card-header">
            <h3 class="card-title">LED 깜빡이기</h3>
          </div>
          <div class="card-body">
            <div class="row">
              <c:forEach begin="1" end="9" step="1" var="num">
                <button class="btn btn-primary col-md-1" onclick="led_start(${num});">${num}</button>&nbsp;&nbsp;
              </c:forEach>
            </div>
          </div>
        </div>
        
        <div class="card card-secondary mt-4">
          <div class="card-header">
            <h3 class="card-title text-center">차량 조작</h3>
          </div>
          <div class="card-body">
            <!-- 방향키 버튼 -->
            <div class="form-group">
              <div class="text-center">
                <button class="btn btn-primary col-md-2" onclick="motor_go('forward');">전진</button>
              </div>
              <div class="text-center mt-3">
                <button class="btn btn-primary col-md-2" onclick="motor_go('left');">좌회전</button>
                <button class="btn btn-primary col-md-2" onclick="motor_go('stop');">정지</button>
                <button class="btn btn-primary col-md-2" onclick="motor_go('right');">우회전</button>
              </div>
              <div class="text-center mt-3">
                <button class="btn btn-primary col-md-2" onclick="motor_go('backward');">후진</button>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

  <!-- Footer -->
  <footer class="container-fluid bg-light mt-4 py-3">
    <div class="container">
      <h3>메세지 칸</h3>
      <!-- 메세지 칸을 여기에 추가 -->
    </div>
  </footer>

  <!-- Bootstrap JS -->
  <script src="https://code.jquery.com/jquery-3.5.1.min.js"></script>
  <!-- LED, Motor Control Script -->
  <script>
    function led_start(num) {
      let url = "built_in/" + num;
      $.ajax({
        "url": url,
        "method": "GET",
        "success": function () { }
      });
    }

    function motor_go(direct) {
      let url = "motor/" + direct;
      $.ajax({
        "url": url,
        "method": "GET",
        "success": function (result) {
          alert(result);
        }
      });
    }

    function ipInput() {
      var ip_form = $("#ip_form").serialize();
      console.log(ip_form);
      let url = "ip_set";
      $.ajax({
        "url": url,
        "data": ip_form,
        "method": "POST",
        "success": function () { }
      });
    }
  </script>
</body>
</html>
