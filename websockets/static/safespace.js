document.addEventListener('DOMContentLoaded', function(){



    var socket = io.connect(location.protocol + '//' + document.domain + ':' + location.port);

    socket.on('connect', function(){
      try{

      document.querySelector("#form").onsubmit = function() {
        socket.emit('chat', {"url":document.URL,"text": document.querySelector("#chat").value})
        document.querySelector("#chat").value = '';
        return false;
      };
    }
    catch{


        document.querySelector("#input").onsubmit =  function() {
          socket.emit('check',{"type":document.querySelector("#text").dataset.type,"name":document.querySelector("#text").value})
          return false;
      };
    };
    });

    socket.on('checked', function(checked){
      try{
      if(checked.success === true){
       document.querySelector("#input").submit()
     }
     else{
       try{
       alert(`Error ${document.querySelector("#text").dataset.type} Taken`);
     }
     catch{};


     };
   }
     catch{};

    });


    socket.on('chatted', function(chats){
      var tabledata = document.createElement("p");
      var text = document.createTextNode(`${chats.timestamp} - ${chats.name}`);
      tabledata.style.fontSize = "small";
      var tabledata2 = document.createElement("p");
      var text2 = document.createTextNode(`${chats.message}`);
      tabledata.appendChild(text);
      tabledata2.appendChild(text2);
      var tabledata3 = document.createElement("td");
      tabledata3.style.color = chats.color;
      tabledata3.appendChild(tabledata);
      tabledata3.appendChild(tabledata2);
      var tabledata4 =  document.createElement("tr");
      tabledata4.appendChild(tabledata3);
      var table = document.getElementById("table");
      table.appendChild(tabledata4);

  });
});
