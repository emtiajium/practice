
function toggleNotice() {
	var notice = document.getElementById('centralNotice');
	if (!wgNoticeToggleState) {
		notice.className = notice.className.replace('collapsed', 'expanded');
		toggleNoticeCookie('0');
	} else {
		notice.className = notice.className.replace('expanded', 'collapsed');
		toggleNoticeCookie('1');
	}
	wgNoticeToggleState = !wgNoticeToggleState;
}
function toggleNoticeStyle(elems, display) {
	if(elems)
		for(var i=0;i<elems.length;i++)
			elems[i].style.display = display;
}
function toggleNoticeCookie(state) {
	var e = new Date();
	e.setTime( e.getTime() + (7*24*60*60*1000) ); // one week
	var work='hidesnmessage='+state+'; expires=' + e.toGMTString() + '; path=/';
	document.cookie = work;
}
function pickTemplate(templates, weights, displayAnons, displayAccounts) {
	var weightedTemplates = new Array();
	var currentTemplate = 0;
	var totalWeight = 0;

	if (templates.length == 0)
		return '';
	
	while (currentTemplate < templates.length) {
		if ((wgUserName && displayAccounts[currentTemplate]) || (!wgUserName && displayAnons[currentTemplate])) {
			totalWeight += weights[currentTemplate];
			for (var i=0; i<weights[currentTemplate]; i++) {
				weightedTemplates[weightedTemplates.length] = templates[currentTemplate];
			}
		}
		currentTemplate++;
	}
	
	if (totalWeight == 0)
		return '';
	
	var randomnumber=Math.floor(Math.random()*totalWeight);
	return weightedTemplates[randomnumber];
}


var wgNoticeToggleState = (document.cookie.indexOf('hidesnmessage=1')==-1);
document.writeln("\x3cstyle type=\"text/css\"\x3e\n#centralNotice .siteNoticeSmall {display:none;}\n#centralNotice .siteNoticeSmallAnon {display:none;}\n#centralNotice .siteNoticeSmallUser {display:none;}\n#centralNotice.collapsed .siteNoticeBig {display:none;}\n#centralNotice.collapsed .siteNoticeSmall {display:block;}\n#centralNotice.collapsed .siteNoticeSmallUser {display:block;}\n#centralNotice.collapsed .siteNoticeSmallAnon {display:block;}\n#centralNotice.anonnotice .siteNoticeSmallUser {display:none !important;}\n#centralNotice.usernotice .siteNoticeSmallAnon {display:none !important;}\n\x3c/style\x3e");

wgNotice=pickTemplate(["\x3c!-- empty --\x3e", "\x3clink rel=\"stylesheet\" type=\"text/css\" href=\"http://wikimediafoundation.org/tracker/bannerImpression.php?total=true\x26req=css\x26site=Wikipedia\x26utm_campaign=test\x26utm_source=test\" /\x3e\n\n\x3cscript type=\"text/javascript\"\x3e  \n\nif( typeof(wgNoticeToggleState) != \"undefined\" ){\n    var isBannerHidden = (wgNoticeToggleState?\"false\":\"true\");\n    if( typeof(wgUserLanguage) == \"undefined\"){\n      wgUserLanguage = \"\";\n    }\n    if( typeof(wgDBname) == \"undefined\"){\n      wgDBname = \"\";\n    }\n    document.write(\"\x3cscript type=\'text/javascript\' src=\'http://wikimediafoundation.org/tracker/bannerImpression.php?hidden=\"+ isBannerHidden +\"\x26req=js\x26site=Wikipedia\x26db=\"+ wgDBname +\"\x26userLang=\"+ wgUserLanguage +\"\x26utm_campaign=test\x26utm_source=test\'\x3e\x3c/scr\" + \"ipt\x3e\");\n}\n\x3c/script\x3e"],[25, 70],[1, 1],[1, 1]);
if (wgNotice != '')
wgNotice='<div id="centralNotice" class="' + (wgNoticeToggleState ? 'expanded' : 'collapsed') + '">' + wgNotice+'</div>';
