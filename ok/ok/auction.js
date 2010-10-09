var flipflop=1;
var storedata = null;
var lastusername;
// call status_handler if %2 = 0
var countdown_sequence = 0;
var countdown_timer;

var lastbutton;
var status_domain = "http://subauction.dmm.com/";

var auctionUpdateTime = 4000;
var counterUpdateTime = 1000;
var auctions = '';
var GlobalVar = 0;

function isNumber(AuctionID) {
	  return !isNaN(parseFloat(AuctionID)) && isFinite(AuctionID);
}

function SetString(str,len)
{
	var strlen = 0; 
	var s = "";
	for (var i = 0;i < str.length;i++)
	{
		if(str.charCodeAt(i) > 128){
			strlen += 2;
		} else {
			strlen++;
		}
		s += str.charAt(i);
		if(strlen >= len){ 
			return s+"..." ;
		}
	}
	return s;
}

function updateStoreData(data)
{
	if (countdown_sequence > 10) {
		if (countdown_timer) {
		    clearInterval(countdown_timer);
		    countdown_timer = 0;
		}
		storedata = data;
		restartCountdownTimer();
		return;
	}
	
	var extend = false;
	
	$.each (data, function (i, item)
	{

		if (!extend && item.auction.extra_countdown != "") {
			extend = true;
			return false;
		}
	});

    if (extend) {
		if (countdown_timer) {
		    clearInterval(countdown_timer);
		    countdown_timer = 0;
		}
		storedata = data;
		restartCountdownTimer();
		return;
    }	
	
	$.each(data, function (i, item)
	{

		if (item.auction.loopstop == 1) {
		   clearInterval(countdown_timer);
		   return;
		}
		
		var o = storedata[i];
		if (o && o.auction.auction_id == item.auction.auction_id) {
		    if (o.auction.last_bidder != item.auction.last_bidder) {
		       o.auction.last_bidder = item.auction.last_bidder;
		    }
		    if (o.auction.current_price != item.auction.current_price) {
		       o.auction.current_price = item.auction.current_price;
		    }
		    if (o.auction.end_date != item.auction.end_date) {
		       o.auction.end_date = item.auction.end_date;
		    }
		    if (o.auction.username != item.auction.username) {
		       o.auction.username = item.auction.username;
		    }
		    if (o.auction.auction_status != item.auction.auction_status) {
		       o.auction.auction_status = item.auction.auction_status;
		    }
		    
		}
		
	});
}

function status_success_callback(data)
{
	
    if (!storedata) {
        storedata = data;
    } else {
        updateStoreData(data);
    }

	$.each(data, function(i, item) {
        var auction_id = item.auction.auction_id;
        var auction_price = item.auction.current_price;
        var auction_bidder_name = item.auction.username;
        var value = item.auction.value;
        if (auction_bidder_name == "") {
            auction_bidder_name = "---";
        }
        if (value == ""){
            value = "---";
        }
		
        var pip = document.getElementById('cdprice_' + auction_id);
		
        if (pip != null &&  pip.innerHTML != auction_price) {
            if (GlobalVar == 1) {
                if ($('.history_auctionid').length) {
                    if (auction_id == document.getElementById('history_auctionid').innerHTML) {
                        var forhoverid = new Spry.Effect.Highlight('cdprice_' + auction_id , {
                            duration: 500,
                            from:'#f79909',
                            to:'#f8f6f3',
                            restoreColor: 'transparent'
                        });
                    } else {
                        forhoverid = new Spry.Effect.Highlight('cdprice_' + auction_id , {
                            duration: 500,
                            from:'#f79909',
                            to:'#fdfdfd',
                            restoreColor: 'transparent'
                        });
                    }
                } else {
                    forhoverid = new Spry.Effect.Highlight('auction_' + auction_id , {
                        duration: 500,
                        from:'#ffeb3f',
                        to:'#ffeb3f',
                        restoreColor: 'transparent'
                    });
                }
                forhoverid.start();
            }


            document.getElementById('cdprice_' + auction_id).innerHTML = auction_price;
			
		    if ($('.productImageThumb').length) {
				document.getElementById('saveprice').innerHTML = "&yen;"+ addCommas(parseInt(document.getElementById('buynowprice').innerHTML) - parseInt(auction_price.replace(",", "")));
			}
			
            var pb = document.getElementById('cdusername_' + auction_id);
            if(pb && pb != 'null'){
                pb.innerHTML = SetString(auction_bidder_name,22);
            }
            //document.getElementById('cdusername_' + auction_id).innerHTML = auction_bidder_name;
            //PennyAuction add for top bidder
            topbidder = item.auction.topbidder;
        //PennyAuction add for top bidder
			
        } else {
            pip = document.getElementById('cdprice_' + auction_id);
            if ($('.history_auctionid').length) {
				
                if (auction_id == document.getElementById('history_auctionid').innerHTML) {
                    if (pip != null){
                        document.getElementById('cdprice_' + auction_id).style.backgroundColor = "transparent";
                    }
                } else {
                    if (pip != null){
                        document.getElementById('cdprice_' + auction_id).style.backgroundColor = "transparent";
                    }
                }
            } else {

                if(pip != null){
                    document.getElementById('cdprice_' + auction_id).style.backgroundColor = "transparent";
                }
            }
        }
    });
    GlobalVar = 1;
	if (!countdown_timer) {
	    countdown_sequence = 0;
	    countdown_timer = setInterval(countdown_handler, 1000);
	}
}

function restartCountdownTimer()
{
	if (countdown_timer) {
	    clearInterval(countdown_timer);
	}
	countdown_sequence = 0;
	countdown_timer = setInterval(countdown_handler, 1000);
}

function status_handler()
{
	
	if (auctions) {
        getStatusUrl = status_domain + 'GetAuctionStatus.php?AuctionID=' + auctions;
        if ($.browser.msie) {
          jQuery('#jsonp').jsonp(getStatusUrl + '&jsonp={fn}', status_success_callback);
        } else {
          jQuery('#jsonp').jsonp(getStatusUrl + '&jsonp={fn}', status_success_callback);
        }
    }
    if (flipflop == 1) {
        flipflop = 2;
    } else if (flipflop == 2) {
        flipflop = 1;
        ChangeCountdownData(storedata);
    }
}

function countdown_handler()
{
    countdown_sequence++;
	$.each(storedata, function(i, item)
	{
		var auction_id = item.auction.auction_id;
		var auction_time = item.auction.countdown - countdown_sequence;
		var pausestatus = item.auction.pause;
		var value = item.auction.value;
		
		if (item.auction.countdown <= -5) {
		    //auction_time = item.auction.countdown;
		}
		var cdtimer = document.getElementById('cdtimer_' + auction_id);
		var cdbutton = document.getElementById('cdbutton_' + auction_id);

		if (auction_time && cdtimer != null && cdbutton != null) {

			
			if ((auction_time <= -5 && item.auction.auction_status == 'Won Auction' )|| auction_time == null) {
				cdtimer.style.color = '#000000';
				cdtimer.innerHTML = "½ªÎ»";
				
				cdbutton.onclick = "";
				cdbutton.name = "";
				cdbutton.onmouseover = "";
				cdbutton.onmouseout = "";
				cdbutton.src = "img/buttons/btn-sold_92.png";
				auctions = auctions.replace(auction_id + "\|", "");
				
			} else if (auction_time <= 0) {
				cdtimer.style.color = '#000000';
				cdtimer.style.fontSize = '18px';
				cdtimer.innerHTML = "½ªÎ»½èÍýÃE..";
			
				cdbutton.onclick = "";
				cdbutton.name  = "placebid.php?AuctionID=" + auction_id;;
				cdbutton.onmouseover = "";
				cdbutton.onmouseout = "";
				cdbutton.src = "img/buttons/btn-sold_92.png";
				

				
			} else if (pausestatus<=0) {
				cdtimer.innerHTML = 'Pause';
				
				cdbutton.src = "img/buttons/btn_placebid_92.png";
				cdbutton.onclick = "";
				cdbutton.onmouseover = "";
				cdbutton.name = "";
				cdbutton.onmouseout = "";
			} else {
				cdtimer.style.fontSize = '21px';
				cdbutton.name = "placebid.php?AuctionID=" + auction_id;
				if (auction_time <= 10) {
					cdtimer.style.color = '#E80000';
					cdtimer.innerHTML = calc_counter_from_time(auction_time);
				} else {
					
					cdtimer.style.color = '#666666';
					cdtimer.innerHTML = calc_counter_from_time(auction_time);
				}
				
				if(document.getElementById("blink_img") != null){
					if (auction_time <= 15){
						document.getElementById("blink_img").style.display='block';
					} else {
						document.getElementById("blink_img").style.display='none';
					}
					
				}
			}
		}
	});
    if (countdown_sequence % 2 == 0) {
        status_handler();
    }
}

function bidhistory_success_callback(data)
{
    //data1 = eval('(' + data.responseText + ')');
    var fontweight;
    //alert(data.histories.length);
    if (data == "" || data.lengh == 0) {
    	return;
    }
    
    for (i=0; i<data.histories.length; i++) {
        biddingprice = data.histories[i].history.bprice;
        biddingusername = data.histories[i].history.username;
        biddingdate = data.histories[i].history.time;						
        biddingtype = data.histories[i].history.type;
	
        if(i==0){
            fontweight="bold";
        }else{
            fontweight="normal";
        }

        $("#bid_price_"+i).html(biddingprice+"±ß");
        $("#bid_price_"+i).css("font-weight", fontweight);

        $("#bid_user_name_"+i).html(SetString(biddingusername,22));
        $("#bid_user_name_"+i).css("font-weight", fontweight);

		$("#bid_type_"+i).html(biddingdate);
        $("#bid_type_"+i).css("font-weight", fontweight);

		$("#bid_types_"+i).html(biddingtype);
        $("#bid_types_"+i).css("font-weight", fontweight);
		
    }

    $("#curproductprice").html(data.histories[0].history.bprice);
}

function ChangeCountdownData(resdata)
{

	var data;
	if (resdata && resdata != "") {
		data = resdata;

	if (storedata.length != data.length) {
	    //storedata = data;
	}
	
	$.each(data, function(i, item)
	{
		
		var o = storedata[i];
		var auction_id = item.auction.auction_id;
		var auction_time = item.auction.countdown - countdown_sequence	;
		var pausestatus = item.auction.pause;
		var value = item.auction.value;

		var cdtimer = document.getElementById('cdtimer_' + auction_id);
		var cdbutton = document.getElementById('cdbutton_' + auction_id);
		
		if (auction_time && cdtimer  != null && cdbutton != null) {
			//alert(auction_time);
			
			if ((auction_time <= -5 && item.auction.auction_status == 'Won Auction' ) /* || auction_time == null */ ) {
				cdtimer.style.color = '#000000';
				cdtimer.innerHTML = "½ªÎ»";
				cdbutton.onclick = "";
				cdbutton.name = "";
				cdbutton.onmouseover = "";
				cdbutton.onmouseout = "";
				cdbutton.src = "img/buttons/btn-sold_92.png";
				auctions = auctions.replace(auction_id + "\|", "");
			} else if (auction_time <= 0) {
				cdtimer.style.color = '#000000';
				cdtimer.style.fontSize = '18px';
				cdtimer.innerHTML = "½ªÎ»½èÍýÃE..";
				cdbutton.onclick="";
				cdbutton.name="placebid.php?AuctionID=" + auction_id;;
				cdbutton.onmouseover="";
				cdbutton.onmouseout="";
				cdbutton.src = "img/buttons/btn-sold_92.png";
			} else if (pausestatus <= 0) {
				cdtimer.innerHTML = 'Pause';
				cdbutton.src = "img/buttons/btn_placebid_92.png";
				cdbutton.onclick = "";
				cdbutton.onmouseover = "";
				cdbutton.name = "";
				cdbutton.onmouseout = "";
			} else {
				cdtimer.style.fontSize = '21px';
				cdbutton.name="placebid.php?AuctionID=" + auction_id;
				if (auction_time <= 10) {
					cdtimer.style.color = '#E80000';
					cdtimer.innerHTML = calc_counter_from_time(auction_time);
				} else {
					
					cdtimer.style.color = '#666666';
					//document.getElementById('cdtimer_' + auction_id).innerHTML = calc_counter_from_time(auction_time);
				}

				if(document.getElementById("blink_img") != null){
					if (auction_time <= 15) {
						document.getElementById("blink_img").style.display = 'block';
					} else {
						document.getElementById("blink_img").style.display = 'none';
					}
					
				}
			}
			}
		});
	}
}


function OnloadPage()
{

    if ($.browser.msie) {
        $.ajaxSetup({
            cache: false
        });	//Configuring ajax
    }

    auctionUpdateTime = 4000;
    counterUpdateTime = 1000;

    auctions = '';

    $('.auction-box').each(function() {
        var auctionId    = $(this).attr('id');
        var auctionTitle = $(this).attr('title');
        if(isNumber(auctionTitle))
        {
        	auctions = auctions + auctionTitle + '|';
        }
    });

    GlobalVar = 0;
    
    if (("is_end_auction" in window) && is_end_auction == true) {
    	//return;
    }
	
    if (false && document.getElementById('tab_history')) {
        setInterval(function() {
            auctionhisid = document.getElementById('history_auctionid').innerHTML;

            oldprice = document.getElementById('curproductprice').innerHTML;
            newprice = document.getElementById('AuctionItem_' + auctionhisid).innerHTML;
            if (oldprice!=newprice) {
                getStatusUrl3 = status_domain + 'getbidhistory.php?id=' + auctionhisid;
                $('#jsonp').json(getStatusUrl3 + '&jsonp={callback}', bidhistory_success_callback);

                //update saving
                var onlineperbidvalue=$("#onlineperbidvalue_text").val();
                var price=$("#price_text").val();
                var fprice=$("#fprice_text").val();
                var aucid=$("#aucid_text").val();

            }
        }, counterUpdateTime);
    }

    //EVENT 
    $('.bid-button-link').click(function() {
    	
		var btn_id = $(this).attr('id');
		if (! btn_id) {
			return false;
		}
		var btn_data = btn_id.split("_");
		if (! btn_data[1]) {
			return false;
		}


		var check_result = true;
		
		nameurl = $(this).attr('name');
		nameparts = nameurl.split("=");

		//¥¹¥Æ¡¼¥¿¥¹
		if(typeof(nameparts[1]) == "undefined")
		{
			alert("¤³¤Î¥ª¡¼¥¯¥·¥ç¥ó¤Ï½ªÎ»¤·¤Þ¤·¤¿¡£");
			return false;
		}		


		$.each(storedata, function (i, item) {
			if (item.auction.auction_id == btn_data[1]) {
				if (item.auction.auction_status == 'Won Auction') {
					check_result = false;
					alert("¤³¤Î¥ª¡¼¥¯¥·¥ç¥ó¤Ï½ªÎ»¤·¤Þ¤·¤¿¡£");
					return;
				}
				
				var auction_time = item.auction.countdown - countdown_sequence	;
				if (auction_time <= -2) {
					check_result = false;
					alert("½èÍýÃæ¤Î¤¿¤áÆþ»¥¤Ç¤­¤Þ¤»¤ó¡£\n¡Ö½ªÎ»½èÍýÃæ¡Ä¡×¤«¤éÀÚ¤EØ¤Eé¤Ê¤¤¾Eç¤Ï¡¢¥Ú¡¼¥¸¤ò¹¹¿·¤·¤Æ¤¯¤À¤µ¤¤¡£");
					return;
		    	}
			}
		});
		if (check_result == false) {
			return false;
		}

		
		
		lastusername = document.getElementById('cdusername_' + nameparts[1]).innerHTML;
		document.getElementById('cdusername_' + nameparts[1]).innerHTML = '½èÍýÃE.';
		
		var cdtime = document.getElementById('cdtimer_' + nameparts[1]).innerHTML;
		
        $.ajax({            
            url: $(this).attr('name'),
            dataType: 'json',
            success: function(data) {

                $.each(data, function(i, item) {
                	
                    result = item.result.split("|");
					if (result[0] == 'pleaselogin') {				
							auction_id = result[1];
							document.location = "https://www.dmm.com/my/=/path=DRVESVwZTlNNBkVRXFhIUwwIGFVfVEs_/";
                            return false;
					}

					if (result[0] == 'd500') {
							
							auction_id = result[1];
							// Last bidder
							// alert ($(this).attr('name'));
                            var pb=document.getElementById('cdusername_' + auction_id);
							UrUsername = pb.innerHTML;
							pb.innerHTML=lastusername;
							alert ("Í¥ÂÔ¥¢¥«¥¦¥ó¥È¤Ç¤ÏÆþ»¥¤Ç¤­¤Þ¤»¤ó¡£"); // If your not a NOVICE User for begginers Only
                            return false;
					}	

					if (result[0] == 'alreadywon') {
							auction_id = result[1];
							
							// Last bidder
							// alert ($(this).attr('name'));
                            var pb=document.getElementById('cdusername_' + auction_id);
							UrUsername = pb.innerHTML;
							pb.innerHTML=lastusername;
							if (document.getElementById('cdtimer_' + auction_id).innerHTML == "½ªÎ»½èÍýÃE..") {
								alert ("½èÍýÃæ¤Î¤¿¤áÆþ»¥¤Ç¤­¤Þ¤»¤ó¡£\n¡Ö½ªÎ»½èÍýÃæ¡Ä¡×¤«¤éÀÚ¤EØ¤Eé¤Ê¤¤¾Eç¤Ï¡¢¥Ú¡¼¥¸¤ò¹¹¿·¤·¤Æ¤¯¤À¤µ¤¤¡£");
							} else {
								alert ("¤³¤Î¥ª¡¼¥¯¥·¥ç¥ó¤Ï½ªÎ»¤·¤Þ¤·¤¿¡£"); // Already Won, Redirect it to the Auction Detail Page
								document.location = "/auction/-/detail/=/aid=" + auction_id;
							}							
                            return false;
					}
					
					
                    if (result[0] == "getnickname") {
							
                		alert('¥Ë¥Ã¥¯¥Í¡¼¥à¤òÅÐÏ¿¤·¤Æ²¼¤µ¤¤¡£');
						document.location = 'https://www.dmm.com/my/-/nickname_input/';
                        return false;
                    }
                    

					if (result[0] == 'prouser') {
							
							auction_id = result[1];
							// Last bidder
							// alert ($(this).attr('name'));
                            var pb=document.getElementById('cdusername_' + auction_id);
							UrUsername = pb.innerHTML;
							pb.innerHTML=lastusername;
							alert ("¥¨¥é¡¼¤¬µ¯¤­¤¿¤¿¤á¡¢¤³¤Î¥ª¡¼¥¯¥·¥ç¥ó¤Ë¤Ï»²²Ã¤Ç¤­¤Þ¤»¤ó¡£"); // If your not a NOVICE User for begginers Only
                            return false;
					}	

                    if (result[0]=="auctionlimit") {
							
							auction_id = result[1];
							// Last bidder
							// alert ($(this).attr('name'));
                            var pb=document.getElementById('cdusername_' + auction_id);
							UrUsername = pb.innerHTML;
							pb.innerHTML=lastusername;
							alert ("Æþ»¥²ÄÇ½¿ô¤òÄ¶¤¨¤Æ¤¤¤EÙ¡¢Æþ»¥¤Ç¤­¤Þ¤»¤ó¡£");
                            return false;
                    }
                    
					if (result[0] == 'topbid') {
							
							auction_id = result[1];
							// Last bidder
							// alert ($(this).attr('name'));
                            var pb=document.getElementById('cdusername_' + auction_id);
							UrUsername = pb.innerHTML;
							
							pb.innerHTML="¤¢¤Ê¤¿¤¬ºÇ¹âÆþ»¥¼Ô¤Ç¤¹¡£";
							forhoverid = new Spry.Effect.Highlight('cdusername_' + auction_id , {
								duration: 500,
								from:'#D61C5B',
								to:'#FFF1AF',
								//restoreColor: '#FFF1AF'
								restoreColor:'transparent'
							});
                            forhoverid.start();
                            setTimeout(function(){pb.innerHTML=SetString(lastusername,22);},3000);
                            return false;
					}
	                if (result[0] == 'bidtimeover') {
                        auction_id = result[1];
                        var pb=document.getElementById('cdusername_' + auction_id);
                        UrUsername = pb.innerHTML;
                        pb.innerHTML=lastusername;
	                    alert("½èÍýÃæ¤Î¤¿¤áÆþ»¥¤Ç¤­¤Þ¤»¤ó¡£\n¡Ö½ªÎ»½èÍýÃæ¡Ä¡×¤«¤éÀÚ¤EØ¤Eé¤Ê¤¤¾Eç¤Ï¡¢¥Ú¡¼¥¸¤ò¹¹¿·¤·¤Æ¤¯¤À¤µ¤¤¡£");
	                    return false;
	                }					
                    if (result[0] == "unsuccess") {
							
						auction_id = result[2];
						var pb = document.getElementById('cdusername_' + auction_id);
						UrUsername = pb.innerHTML;
						pb.innerHTML = lastusername;
                        if (result[1] == -32) {
                            alert("¥Ý¥¤¥ó¥ÈÉÔÂ­¤Î¤¿¤á¡¢Æþ»¥¤Ç¤­¤Þ¤»¤ó¡£");
                            return false;
                        } else if (result[1] == -31) {
                        	alert("¥Ý¥¤¥ó¥È¤ò¹ØÆþ¤·¤Æ²¼¤µ¤¤¡£");
                        	window.location.href='http://www.dmm.com/auction/-/point_purchase/';
                            return false;
                        }
                    }
                    
                    if (result[0] == "discount_bought") {
                    	alert("ÃÍ°ú¤­¹ØÆþºÑ¤ß¤Î°Ù¡¢Æþ»¥¤Ç¤­¤Þ¤»¤ó¡£");
                    	return false;
                    }
                    
                    if (result[0] == "inactive") {
                    	alert("¤³¤Î¥ª¡¼¥¯¥·¥ç¥ó¤Ï¤¹¤Ç¤Ë½ªÎ»¤·¤Æ¤¤¤Þ¤¹¡£");
                    	return false;
                    }                    
                    
                    if (result[0] == "error") {
                    	alert("¥¨¥é¡¼¤¬È¯À¸¤·¤Þ¤·¤¿¡£ºÆÅÙÆþ»¥¤·¤Æ¤¯¤À¤µ¤¤¡£\n"+result[1]);
                    	return false;
                    }
                    
                    if (result[0] == "success") {
                        $("#bids_count").text(result[3]);
                    }                    
                });
            },
            error: function(XMLHttpRequest,textStatus, errorThrown) {}
        });

        return false;
    });


    status_handler();
}


function calc_counter_from_time(diff)
{
    if (diff > 0) {
        hours=Math.floor(diff / 3600)
        minutes=Math.floor((diff / 3600 - hours) * 60)
        seconds=Math.round((((diff / 3600 - hours) * 60) - minutes) * 60)
    } else {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    if (seconds == 60) {
        seconds = 0;
    }

    if (minutes < 10) {
        if (minutes < 0) {
            minutes = 0;
        }
        minutes = '0' + minutes;
    }

    if (seconds < 10) {
        if (seconds < 0) {
            seconds = 0;
        }
        seconds = '0' + seconds;
    }

    if (hours < 10) {
        if (hours < 0) {
            hours = 0;
        }
        hours = '0' + hours;
    }
    return hours + ":" + minutes + ":" + seconds;
}



function addCommas(nStr)
{
	nStr += '';
	x = nStr.split('.');
	x1 = x[0];
	x2 = x.length > 1 ? '.' + x[1] : '';
	var rgx = /(\d+)(\d{3})/;
	while (rgx.test(x1)) {
		x1 = x1.replace(rgx, '$1' + ',' + '$2');
	}
	return x1 + x2;
}

$(document).ready(
	function() {
	    OnloadPage();
	}
);
