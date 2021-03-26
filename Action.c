Action()
{
	
	char * CatagoryID;
	char * CatagoryName;

	char * ItemID;
	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_set_max_html_param_len("99999");
	
	//viewCategory=&amp;categoryId=FISH"><
	
//	web_reg_save_param("C_CatagoryName","LB=","RB=","ORD=",LAST);
	

	web_reg_save_param("C_CatagoryName","LB=viewCategory=&amp;categoryId=","RB=\">","ORD=ALL",LAST);
	
	
	lr_start_transaction("00_Launch");

	
	web_url("Account.action", 
		"URL=https://petstore.octoperf.com/actions/Account.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		EXTRARES, 
//		"Url=https://content-autofill.googleapis.com/v1/pages/ChNDaHJvbWUvODkuMC40Mzg5LjkwEhAJ34e8yo8bLA8SBQ0Cj_toEhcJPBi8VCVDHfASBQ3njUAOEgUNzkFMeg==?alt=proto", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("00_Launch", LR_AUTO);

	web_add_header("Origin", 
		"https://petstore.octoperf.com");

	lr_start_transaction("01_login");

	
	web_submit_data("Account.action;jsessionid=8DAF18DB7C1C5EDBA56E55157E0F24FE", 
		"Action=https://petstore.octoperf.com/actions/Account.action;jsessionid=8DAF18DB7C1C5EDBA56E55157E0F24FE", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=j2ee", ENDITEM, 
		"Name=password", "Value=j2ee", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=tXmYev1oBh8rz96lkuVocBOcuszgfOwrN8afMhkhI5aYHWrhU6W_cH4pwFvJVHz989zdXOz9Vpy7GCqbI72cOe3LYK8otIhxzDgJSi9vpno=", ENDITEM, 
		"Name=__fp", "Value=af3tEPv_mXTnQjOxXZK7slAf1egHSK2-dAts7xaAkEjC8m2cYFiAObo5F1f_6r5c", ENDITEM, 
		LAST);

	lr_end_transaction("01_login",LR_AUTO);

	
	CatagoryName = lr_paramarr_random("C_CatagoryName");
	
	lr_save_string(CatagoryName,"CatagoryName");
	lr_output_message("We are on CatagoryName #%s", CatagoryName ); 
	
	
	lr_think_time(22);

	//actions/Catalog.action?viewProduct=&amp;productId=FI-FW-02">
	
	web_reg_save_param("C_CatagoryID","LB=actions/Catalog.action?viewProduct=&amp;productId=","RB=\">","ORD=ALL",LAST);
	
	
	
	lr_start_transaction(lr_eval_string("02_SelectCatagory_{CatagoryName}" ));
	
	                     

	                     	
	                     	
	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId={CatagoryName}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("02_SelectCatagory_{CatagoryName}" ),LR_AUTO);

	CatagoryID = lr_paramarr_random("C_CatagoryID");
	
	lr_save_string(CatagoryID,"CatagoryID");
	
	lr_output_message("We are on CatagoryID #%s", CatagoryID );
	
	                  
	 //actions/Catalog.action?viewItem=&amp;itemId=EST-20">

	 web_reg_save_param("C_ItemID","LB=actions/Catalog.action?viewItem=&amp;itemId=","RB=\">","ORD=ALL",LAST);
		 
	lr_think_time(62);

	lr_start_transaction(lr_eval_string("03_Select_{CatagoryName}_{CatagoryID}" ));

	web_url("FI-FW-02", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId={CatagoryID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId={CatagoryName}", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("03_Select_{CatagoryName}_{CatagoryID}" ),LR_AUTO);

	
	ItemID = lr_paramarr_random("C_ItemID");
	
	lr_save_string(ItemID,"ItemID");
	
	lr_output_message("We are on ItemID #%s", ItemID  );
	lr_think_time(10);

	lr_start_transaction(lr_eval_string("04_AddToCard_for {CatagoryName}_{ItemID}"));

	web_url("Add to Cart", 
		"URL=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId={ItemID}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewProduct=&productId={CatagoryID}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://safebrowsing.googleapis.com/v4/threatListUpdates_fetch?$req="
		"ChwKDGdvb2dsZWNocm9tZRIMODkuMC40Mzg5LjkwGicIARABGhkKDQgBEAYYASIDMDAxMAMQFBoCGARPXULuIgQgASACKAMaJwgJEAEaGQoNCAkQBhgBIgMwMDEwBhADGgIYBDI7R8MiBCABIAIoBhopCAcQARobCg0IBxAGGAEiAzAwMTABEPqPCRoCGAT1FwH1IgQgASACKAEaKQgFEAEaGwoNCAUQBhgBIgMwMDEwARCN6AoaAhgE1mgAvSIEIAEgAigBGigIARAIGhoKDQgBEAgYASIDMDAxMAQQoR4aAhgEvUBfhSIEIAEgAigEGicICRABGhkKDQgJEAYYASIDMDAxMAEQHxoCGASdmKtKIgQgASACKAEaKAgIEAEaGgoNCAgQBhgBIgMwMDEwARDXCxoCGATJ4evPIgQgASACKAEaKQgNEAEaGwoNCA0QBhgBIgMwMDEwARCdhgEaAhgEaFVOoCIEIAEgAigBGikIARABGhsKDQ"
		"gBEAYYASIDMDAxMAEQ-9MIGgIYBLUC_MciBCABIAIoARonCAoQCBoZCg0IChAIGAEiAzAwMTABEAYaAhgEcSpGWiIEIAEgAigBGikIAxABGhsKDQgDEAYYASIDMDAxMAEQycsIGgIYBPKzVGkiBCABIAIoARooCBAQARoaCg0IEBAGGAEiAzAwMTABEMwJGgIYBHCol8IiBCABIAIoARopCA4QARobCg0IDhAGGAEiAzAwMTABEPyfBRoCGAQW3VJaIgQgASACKAEaKAgPEAEaGgoNCA8QBhgBIgMwMDEwARDoXBoCGATd0MhrIgQgASACKAEiAggD&$ct=application/x-protobuf&key=AIzaSyBOti4mM-6x9WDnZIjIeyEU21OpBXqWBgw", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction(lr_eval_string("04_AddToCard_for {CatagoryName}_{ItemID}"),LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("05_proceedTo checkout");

	web_url("Proceed to Checkout", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Cart.action?addItemToCart=&workingItemId={ItemID}", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("05_proceedTo checkout",LR_AUTO);

	lr_start_transaction("06_Payment_Continue");

	web_add_header("Origin", 
		"https://petstore.octoperf.com");

	lr_think_time(10);

	web_submit_data("Order.action", 
		"Action=https://petstore.octoperf.com/actions/Order.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrderForm=", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=order.cardType", "Value=Visa", ENDITEM, 
		"Name=order.creditCard", "Value=999 9999 9999 9999", ENDITEM, 
		"Name=order.expiryDate", "Value=12/03", ENDITEM, 
		"Name=order.billToFirstName", "Value=ABC", ENDITEM, 
		"Name=order.billToLastName", "Value=XYX", ENDITEM, 
		"Name=order.billAddress1", "Value=901 San Antonio Road", ENDITEM, 
		"Name=order.billAddress2", "Value=MS UCUP02-206", ENDITEM, 
		"Name=order.billCity", "Value=Palo Alto", ENDITEM, 
		"Name=order.billState", "Value=CA", ENDITEM, 
		"Name=order.billZip", "Value=94303", ENDITEM, 
		"Name=order.billCountry", "Value=USA", ENDITEM, 
		"Name=newOrder", "Value=Continue", ENDITEM, 
		"Name=_sourcePage", "Value=TpeK1LdAR1Dn8YVN2z2A8fj6ILwXZ__L34S4WLypZ4zlt8ZjJAstF-RgqNaL1p_BEYYkJQAPUInEVWIj6DcpC-qJoid9b34r8wmUqHrL39k=", ENDITEM, 
		"Name=__fp", "Value=-_jPnrhss6ZddJtaX_a4E8qI0FNux9aCUyADmGkTWStmtz-iSHISQNiwVVJN3yXj7vRCJTYkLRCBtCXVyHmHDLg4qJSNz-j4nc37c342EJoD8wY89YA2dg==", ENDITEM, 
		LAST);

	lr_end_transaction("06_Payment_Continue",LR_AUTO);

	lr_think_time(10);

	lr_start_transaction("07_confirm");

	web_url("Confirm", 
		"URL=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("07_confirm",LR_AUTO);

	lr_start_transaction("08_SignOUT");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Order.action?newOrder=&confirmed=true", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("08_SignOUT",LR_AUTO);

	return 0;
}