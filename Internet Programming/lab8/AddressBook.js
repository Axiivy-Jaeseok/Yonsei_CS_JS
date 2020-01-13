var webServiceUrl = "http://localhost:81"
var nameValid = false;


function showCDBook()
{
	//alert('showAddressBook')
	document.getElementById("addEntry").style.display = "none";
	document.getElementById("CDCatalogBook").style.display = "block";
	callWebService("/getAllNames", parseData);
}

function setArguments(methodAndArguments)
{
	var arr = methodAndArguments.split('/')
	var method = '/'+ arr[1] + '.php'
    var Arguments = ''
    for(var i = 2; arr.length>i; i++){
    	var parName = 'P'
    	Arguments +=parName +(i-1)+ '='+arr[i]+'&'
    }

    if(Arguments == '')
    {
    	return method
    }else{
    	return method +'?'+encodeURI(Arguments)
    }

}
function callWebService(methodAndArguments, callBack)
{
	var requestUrl = webServiceUrl + setArguments(methodAndArguments);
    //alert(requestUrl) 
	try{
		var asyncRequest = new XMLHttpRequest();
		asyncRequest.addEventListener("readystatechange", function(){callBack(asyncRequest);}, false);
		asyncRequest.open("GET", requestUrl, true);
		asyncRequest.send();

	}catch(exception)
	{
		alert("Request Failed")
	}
}

function parseData(asyncRequest)
{
	
	if(asyncRequest.readyState == 4 && asyncRequest.status ==200)
	{
		var data = JSON.parse(asyncRequest.responseText);
		displayNames(data);
	}
}


function displayNames(data)
{
	//alert('displayNames')
	var listBox = document.getElementById("Names");
	listBox.innerHTML = "";

	for (var i=0; i < data.length ; ++i)
	{
		var entry = document.createElement("div");
		var field = document.createElement("fieldset");
	
		entry.id = i;
		entry.innerHTML = data[i].NAME;
		field.appendChild(entry);
		listBox.appendChild(field);
	}
}

function search(input)
{
	var listBox = document.getElementById('Names');
	listBox.innerHTML = "";

	if(input == ""){
		showCDBook();
	}else{
		callWebService("/search/" + input, parseData);
	}
}



function clearField( entry, name)
{
	entry.innerHTML = name;
	entry.onclick = function() {getAddress(entry, name);};
}

function addEntry ()
{
	//alert('addEntry')
	document.getElementById("CDCatalogBook").style.display= "none";
	document.getElementById("addEntry").style.display = "block";
}


function validateName(name)
{
	//alert('validateZip-'+zip)
	callWebService("/validateName/"+name, showState);

}


function showState(asyncRequest)
{
	
	if( asyncRequest.readyState ==4 )
	{
		if( asyncRequest.status == 200)
		{
			var data = JSON.parse(asyncRequest.responseText);

			if(data.Validity == "Valid")
			{
				nameValid = true;
				document.getElementById("validateName").innerHTML = "";
			}else
			{
				nameValid = false;
				document.getElementById("validateName").innerHTML = data.ErrorText;
			}
		}
	}
}

function saveForm()
{
	//alert('saveForm')
	var title = document.getElementById("title").value;
	var artist = document.getElementById("artist").value;
	var country = document.getElementById("country").value;

	var company = document.getElementById("company").value;
	var price = document.getElementById("price").value;
	var year = document.getElementById("year").value;

	if(!nameValid)
	{
		document.getElementById("success").innerHTML = "Invalid data entered. Check form for more information";
	}
	else 
	{
		document.getElementById("addEntry").style.display = "none";
		document.getElementById("CDCatalogBook").style.display = "block";

		callWebService("/addEntry/" + title + "/" + artist + "/" + country + "/" + company + "/" + price + "/" + year, parseData);
		
	}

}

function start()
{

	document.getElementById("CDCatalogButton").addEventListener("click", showCDBook , false);
	document.getElementById("addEntryButton").addEventListener("click", addEntry, false);
	document.getElementById("searchInput").addEventListener("keyup",function(){ search(this.value) }, false);
	document.getElementById("artist").addEventListener("blur", function(){validateName(this.value)}, false);
	document.getElementById("submitButton").addEventListener("click", saveForm, false);

	showCDBook();
}

window.addEventListener("load", start , false);