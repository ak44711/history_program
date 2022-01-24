<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!-- 引入 Bootstrap -->
    <link href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet">
</head>
<body>
<form action="upload" method="POST" enctype="multipart/form-data">
    图片描述：<input type="text" name="name" size="20"><br/><br/>
    选择文件：<input type="file" name="file" value="" /> <br />
    <input type="submit" name="upload" value="上传" />
</form>
</body>
</html>