$(	//same as doc.addevelistener.. ie an iife
	function ()
	{
		//document.querySelector(".navbar-toggler").addEventListener("blur")
		// $(".navbar-toggler").blur
		// (
		// 	function(event)
		// 	{
		// 		var screenWidth=window.innerWidth;
		// 		if(screenWidth<992)
		// 			$("#navbarNavAltMarkup").collapse('hide');
		// 	}
		// );

		$(document).click(function (event) {
		    $('.navbar-collapse').collapse('hide');
		  });

	}
);

(
	function(global)
	{

		var ph={};

		var homeHtml="snippets/home-snippet.html";
		var aboutHtml="snippets/about-snippet.html";
		var awardsHtml="snippets/awards-snippet.html";
		var allCatsUrl="js/plant-cats.json";
		var catTitle="snippets/cat-title-snippet.html";
		var cathtml="snippets/cat-snippet.html";
		var planttypes="js/sing-cats.json";
		var planttypestitle="snippets/sing-cat-title-snippet.html";
		var planttypeshtml="snippets/sing-cat-snippet.html";
		var specials="js/specials.json";
		var specialstitle="snippets/specials-title-snippet.html";
		var specialshtml="snippets/specials-snippet.html";
		var categoryname;

		//convinience funct for ins innerHTML for select
		var insHTML=
			function(selector, html)
			{
				var targetele=document.querySelector(selector);
				targetele.innerHTML=html;
			};

			//show loading icon inside ele identified by selector
		var showLoading=
			function(selector)
			{
				var html="<div class='text-center'>";
				html+="<img src='images/ajax-loader.gif'></div>"
				insHTML(selector, html);
			};

		//return substitute of {{propName}}
		var insProperty=
			function(string, propName, propValue)
			{
				var propToReplace="{{"+propName+"}}";
				string=string.replace(new RegExp(propToReplace, "g"), propValue);
				return string;
			};

		
		var switching= 
			function()
			{
				//make home inactive when we're on types
				var classes=document.querySelector("#home").className;
				classes=classes.replace(new RegExp("active", "g"), "");
				document.querySelector("#home").className=classes;

				//make home inactive when we're on types
				classes=document.querySelector("#hi").className;
				if (classes.indexOf("active"))
				{
					classes=classes.replace(new RegExp("active", "g"), "");
					document.querySelector("#hi").className=classes;
				}

				//make home inactive when we're on types
				classes=document.querySelector("#hi2").className;
				if (classes.indexOf("active"))
				{
					classes=classes.replace(new RegExp("active", "g"), "");
					document.querySelector("#hi2").className=classes;
				}

				//add active to types button
				classes=document.querySelector("#pat").className;
				if (classes.indexOf("active")==-1)
				{
					classes+=" active";
					document.querySelector("#pat").className=classes;
				}
			};


		var switching2= 
			function()
			{
				//make home inactive when we're on types
				var classes=document.querySelector("#home").className;
				classes=classes.replace(new RegExp("active", "g"), "");
				document.querySelector("#home").className=classes;

				//make home inactive when we're on types
				classes=document.querySelector("#pat").className;
				if (classes.indexOf("active"))
				{
					classes=classes.replace(new RegExp("active", "g"), "");
					document.querySelector("#pat").className=classes;
				}

				//make home inactive when we're on types
				classes=document.querySelector("#hi2").className;
				if (classes.indexOf("active"))
				{
					classes=classes.replace(new RegExp("active", "g"), "");
					document.querySelector("#hi2").className=classes;
				}

				//add active to types button
				classes3=document.querySelector("#hi").className;
				if (classes3.indexOf("active")==-1)
				{
					classes3+=" active";
					document.querySelector("#hi").className=classes3;
				}
			};



			var switching3= 
			function()
			{
				//make home inactive when we're on types
				var classes=document.querySelector("#home").className;
				classes=classes.replace(new RegExp("active", "g"), "");
				document.querySelector("#home").className=classes;

				//make home inactive when we're on types
				classes=document.querySelector("#pat").className;
				if (classes.indexOf("active"))
				{
					classes=classes.replace(new RegExp("active", "g"), "");
					document.querySelector("#pat").className=classes;
				}

				//make home inactive when we're on types
				classes=document.querySelector("#hi").className;
				if (classes.indexOf("active"))
				{
					classes=classes.replace(new RegExp("active", "g"), "");
					document.querySelector("#hi").className=classes;
				}

				//add active to types button
				classes3=document.querySelector("#hi2").className;
				if (classes3.indexOf("active")==-1)
				{
					classes3+=" active";
					document.querySelector("#hi2").className=classes3;
				}
			};


		//on page load
		document.addEventListener
		(
			"DOMContentLoaded", function(event)
			{
				showLoading("#mainc");
				$ajaxUtils.sendGetRequest
				(
					homeHtml, function(responseText)
					{
						document.querySelector("#mainc").innerHTML=responseText;
					}, false
				);
			}
		);



		//load about
		ph.loadAbout= 
			function()
			{
				showLoading("#mainc");
				switching2();
				$ajaxUtils.sendGetRequest
				(
					aboutHtml, function(responseText)
					{
						document.querySelector("#mainc").innerHTML=responseText;
					}, false
				);
			};



		//load awards
		ph.loadAwards= 
			function()
			{
				showLoading("#mainc");
				switching3();
				$ajaxUtils.sendGetRequest
				(
					awardsHtml, function(responseText)
					{
						document.querySelector("#mainc").innerHTML=responseText;
					}, false
				);
			};


		//load plant categories view
		ph.loadPlantCat= 
			function()
			{
				showLoading("#mainc");
				$ajaxUtils.sendGetRequest(allCatsUrl, showCatsHtml);
			};


		//load plant types
		ph.loadSingCat=
			function(catname)
			{
				showLoading("#mainc");
				categoryname=catname;
				$ajaxUtils.sendGetRequest(planttypes, showTypesHtml);
			};

		//load specials
		ph.loadSpecials=
			function()
			{
				showLoading("#mainc");
				$ajaxUtils.sendGetRequest(specials, showSpecialsHtml);
			};


		//builds html for cat page based on data from server
		function showCatsHtml(cats) 
		{
			$ajaxUtils.sendGetRequest
			(
				catTitle, function(catTitle)
				{
					//retirive single cat snippet
					$ajaxUtils.sendGetRequest
					(
						cathtml, function(cathtml)
						{

							switching();
							var catViewHtml=buildCatView(cats, catTitle, cathtml);
							insHTML("#mainc", catViewHtml);
						}, false
					);
				}, false
			);
		}

		function buildCatView(cats, catTitle, cathtml) 
		{

			var finalhtml=catTitle;
			finalhtml+= "<section class='row'>";

			for(var i=0;i<cats.length; i++)
			{
				var html=cathtml;
				var name=cats[i].name;
				html=insProperty(html, "name", name);
				finalhtml+= html;
			}
			finalhtml+="</section>";
			return finalhtml;
		}



		//types view
		//types of plants
		function showTypesHtml(allcats)
		{
			$ajaxUtils.sendGetRequest
			(
				planttypestitle, function(planttypestitle)
				{
					//retirive single cat snippet
					$ajaxUtils.sendGetRequest
					(
						planttypeshtml, function(planttypeshtml)
						{
							switching();
							var typesViewHtml=buildTypesView(allcats, planttypestitle, planttypeshtml);
							insHTML("#mainc", typesViewHtml);
						}, false
					);
				}, false
			);
		}


		function buildTypesView(allcats, planttypestitle, planttypeshtml) 
		{
			for(var j=0;j<allcats.length;j++)
			{
				console.log
				if(allcats[j].catname==categoryname)
					break;
			}
			planttypestitle=insProperty(planttypestitle,"name",allcats[j].catname);
			planttypestitle=insProperty(planttypestitle,"specialinst",allcats[j].cats[1].specialinst);
			
			var finalhtml=planttypestitle;
			finalhtml+="<section class='row'>";

			for(var i=0;i<allcats[j].cats.length; i++)
			{
				var html=planttypeshtml;
				html=insProperty(html, "tname", allcats[j].cats[i].tname);
				html=insProperty(html, "code", allcats[j].cats[i].code);
				html=insProperty(html, "desc", allcats[j].cats[i].desc);
				finalhtml+= html;
			}
			finalhtml+="</section>";
			return finalhtml;
		}


		//builds html for specials page based on data from server
		function showSpecialsHtml(spes) 
		{
			$ajaxUtils.sendGetRequest
			(
				specialstitle, function(specialstitle)
				{
					//retirive single cat snippet
					$ajaxUtils.sendGetRequest
					(
						specialshtml, function(specialshtml)
						{

							switching();
							var specialsViewHtml=buildSpecialsView(spes, specialstitle, specialshtml);
							insHTML("#mainc", specialsViewHtml);
						}, false
					);
				}, false
			);
		}

		function buildSpecialsView(spes, specialstitle, specialshtml) 
		{
			console.log(spes.length);
			var finalhtml=specialstitle;
			finalhtml+= "<section class='row'>";

			for(var i=0;i<spes.length; i++)
			{
				var html=specialshtml;
				var name=spes[i].name;
				html=insProperty(html, "name", name);
				finalhtml+= html;
			}
			finalhtml+="</section>";
			return finalhtml;
		}


		global.$ph=ph;
	}
)(window);