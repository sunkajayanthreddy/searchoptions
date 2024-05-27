Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_set_sockets_option("TLS_SNI", "0");

	web_add_auto_header("Accept-Language", 
		"en-IN,en;q=0.9");

	web_url("Catalog.action", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("TLS_SNI", "1");

	lr_think_time(32);

	lr_start_transaction("Signin");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=84DDBDD3F98493761E72D89C534B8CE7?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("TLS_SNI", "0");

	lr_end_transaction("Signin",LR_AUTO);

	lr_start_transaction("Login");

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=84DDBDD3F98493761E72D89C534B8CE7?signonForm=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=j2ee", ENDITEM, 
		"Name=password", "Value=j2ee", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=lE_P1AA7WxGHtQxhx_GP3dvuorqqE1bQKy09XoHvP4IeLfmm_0aZeldyfjTevjSEcxi08AuDskrcGFiuP52Bw_xcN83mIWLzww6FmVDDePQ=", ENDITEM, 
		"Name=__fp", "Value=iIKAGQkVrl_Pts8Vr9JDHD9p_3XXLlTmNtaFHo1ATz3kmyTsohiokd6RyahVaQF5", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(8);

	lr_start_transaction("Click_on_Search");

	web_submit_data("Catalog.action_2", 
		"Action=https://petstore.octoperf.com/actions/Catalog.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=keyword", "Value=", ENDITEM, 
		"Name=searchProducts", "Value=Search", ENDITEM, 
		"Name=_sourcePage", "Value=Jq3r640-niuhEev-jG409qNVpm3j3loycJ2f7hIdZ3XjzJX9UJYdO9j6EL69VEV54I2j6byUEmw4rQOo6xhpxwdcw0DhfORM", ENDITEM, 
		"Name=__fp", "Value=qCWvkIPuS1LC1QNJ9g3doLnYXlkuOu03nZapqhL292V7n7U-tw-lfD0actYeJ_O2", ENDITEM, 
		LAST);

	lr_think_time(28);

	web_submit_data("Catalog.action_3", 
		"Action=https://petstore.octoperf.com/actions/Catalog.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=keyword", "Value=dog", ENDITEM, 
		"Name=searchProducts", "Value=Search", ENDITEM, 
		"Name=_sourcePage", "Value=B1zo3J--OfoMoUiTITSMCwW540E40Drwxh01pLKiWbRRXZt-cLmVvSxkTiVyPgrdMpgacYdM-z94Q0Qwfho1WK5OMLlUBCh1", ENDITEM, 
		"Name=__fp", "Value=f_-lPeJ1WhgKVQUbt41wgqEbA5jXRCtvXVii85fKAXXHmNpRW0YydswK8uKHkbkH", ENDITEM, 
		LAST);

	lr_end_transaction("Click_on_Search",LR_AUTO);

	lr_start_transaction("Signoff");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Signoff",LR_AUTO);

	return 0;
}