function initaccordion(accordionelem){
     
//when panel is clicked, handpanelclick is called.

    function handpanelclick(Event){
        showpanel(Event.currenttarget);
    }
    
    //hide currentpanel and show new panel.
    
    function showpanel(panel){
        //hide current one.first time it will be null.
        var expandedpanel=accordionelem.queryselector(".active");
        if (expandedpanel){
            expandedpanel.classlist.remove("active");
        }
        
        //show new one 
        panel.classlist.add("active");
    }
    
    var allpanelelems = accordionelem.queryselectoeall(".panel");
    for (var i=0, len=allpanelelems.length;i<len; i++){
        allpanelelems[i].addEventListener("click",handpanelclick);
    }
    
    //by default show first panel
    showpanel(allpanelelems[0])
}

initaccordion(document.getElementById("accordion"));