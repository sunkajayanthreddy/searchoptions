Action()
{


    web_set_sockets_option("SSL_VERSION", "AUTO");

	web_set_sockets_option("TLS_SNI", "0");
	
	
	
	web_reg_save_param("C_Jsessionid","lb=Catalog.action;jsessionid=","rb=\"",LAST);
	
	web_reg_save_param("C_CategoryId","lb=viewCategory=&amp;categoryId=","rb=\"",LAST);
	
	lr_start_transaction("JpetStore_SC03_TC01_Launch");
	
    web_reg_find("text=Elevate you load-testing with","savecount=ElevateCount",LAST);
    
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
	
	if(atoi(lr_eval_string("{ElevateCount}"))>0) 
	 {
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC03_TC01_Launch",LR_PASS);
	}
	else
	{
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC03_TC01_Launch",LR_AUTO);
       lr_abort();
	}

	
	lr_think_time(2);

	
	web_reg_save_param("C_SourcePage","lb=name=\"_sourcePage\" value=\"","rb=\"",LAST);
	
	web_reg_save_param("C_Fp","lb=name=\"__fp\" value=\"","rb=\"",LAST);
	
	lr_start_transaction("JpetStore_SC03_TC02_Signin");
	
	web_reg_find("text=Need a user name and password","savecount=NeedCount",LAST);

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_Jsessionid}?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{NeedCount}"))>0)
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC03_TC02_Signin",LR_PASS);
	}
	else 
	{
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC03_TC02_Signin",LR_AUTO);
       lr_abort();
	}
	
	
	lr_think_time(2);
	
	web_reg_save_param("C_SourcePage_01","lb=name=\"_sourcePage\" value=\"","rb=\"",LAST);
	
	web_reg_save_param("C_Fp_01","lb=name=\"__fp\" value=\"","rb=\"",LAST);
	
	lr_start_transaction("JpetStore_SC03_TC03_Login");
	
	web_reg_find("text=Welcome ABC!","savecount=WelcomeABC!Count",LAST);

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid={C_Jsessionid}?signonForm=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={P_UN}", ENDITEM, 
		"Name=password", "Value={P_PSWD}", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value={C_SourcePage}", ENDITEM, 
		"Name=__fp", "Value={C_Fp}", ENDITEM, 
		LAST);
	
	if(atoi(lr_eval_string("{WelcomeABC!Count}"))>0)
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC03_TC03_Login",LR_PASS);
	}
	else
	{
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC03_TC03_Login",LR_AUTO);
       lr_abort();
	}
	

	lr_think_time(2);
	
	web_reg_save_param("C_SourcePage_02","lb=name=\"_sourcePage\" value=\"","rb=\"",LAST);
	
	web_reg_save_param("C_Fp_02","lb=name=\"__fp\" value=\"","rb=\"",LAST);

	lr_start_transaction("JpetStore_SC03_TC04_Click_on_Search");
	
	web_reg_find("text=Please enter a keyword to search for, then press the search button.","savecount=PleaseenterCount",LAST);
	
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
		"Name=_sourcePage", "Value={C_SourcePage_01}", ENDITEM, 
		"Name=__fp", "Value={C_Fp_01}", ENDITEM, 
		LAST);

	lr_think_time(2);

	web_submit_data("Catalog.action_3", 
		"Action=https://petstore.octoperf.com/actions/Catalog.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=keyword", "Value={C_CategoryId}", ENDITEM, 
		"Name=searchProducts", "Value=Search", ENDITEM, 
		"Name=_sourcePage", "Value={C_SourcePage_02}", ENDITEM, 
		"Name=__fp", "Value={C_Fp_02}", ENDITEM, 
		LAST);
	
	if(atoi(lr_eval_string("{PleaseenterCount}"))>0)
	{
		 lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC03_TC04_Click_on_Search",LR_PASS);
	}
	else
	{
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC03_TC04_Click_on_Search",LR_AUTO);
       lr_abort();
	}
	
	lr_think_time(2);

	lr_start_transaction("JpetStore_SC03_TC05_Signoff");
	
	web_reg_find("text=Exotic Varieties","savecount=ExoticCount",LAST);

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	if(atoi(lr_eval_string("{ExoticCount}"))>0)
	{
		lr_output_message("Valid Response");
		lr_end_transaction("JpetStore_SC03_TC05_Signoff",LR_PASS);
	}
	else
	{
	   lr_output_message("Invalid Response");
       lr_end_transaction("JpetStore_SC03_TC05_Signoff",LR_AUTO);
       lr_abort();
	}

	return 0;
}