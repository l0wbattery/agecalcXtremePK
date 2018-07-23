angular.module('app', ['ngRoute','toastr']);

angular.module('app')
.config(function ($routeProvider) {

    $routeProvider

        // http://localhost:8080/#!/pokemon

        .when('/agecalc', {
            templateUrl: 'agecalc/agecalc.html',
            controller: 'agecalcCtrl'
        })

        .when('/home', {
            templateUrl: 'home/index.html',
            controller: 'homeCtrl'
        })
        
        ///itens
        .when('/espadas', {
            templateUrl: 'itens/espada/espada.html',
            controller: 'espadaCtrl'
        })
        .when('/aneis', {
            templateUrl: 'itens/anel/anel.html',
            controller: 'anelCtrl'
        })
        .when('/arcos', {
            templateUrl: 'itens/arco/arco.html',
            controller: 'arcoCtrl'
        })
        .when('/machados', {
            templateUrl: 'itens/axe/axe.html',
            controller: 'axeCtrl'
        })
        .when('/garras', {
            templateUrl: 'itens/garra/garra.html',
            controller: 'garraCtrl'
        })
        .when('/cajados', {
            templateUrl: 'itens/cajado/cajado.html',
            controller: 'cajadoCtrl'
        })
        .when('/escudos', {
            templateUrl: 'itens/escudo/escudo.html',
            controller: 'escudoCtrl'
        })
        .when('/foices', {
            templateUrl: 'itens/foice/foice.html',
            controller: 'foiceCtrl'
        })
        .when('/lancas', {
            templateUrl: 'itens/lanca/lanca.html',
            controller: 'lancaCtrl'
        })
        .when('/armaduras', {
            templateUrl: 'itens/armadura/armadura.html',
            controller: 'armaduraCtrl'
        })
        ///////

        .otherwise('/home');
});


angular.module('app').controller('homeCtrl',['$scope','$route','toastr', function ($scope,$route,toastr) {
    $scope.selecionado = false;
    $scope.onSelectItem = onSelectItem;
    $scope.calcularAgeItem = calcularAgeItem;
    $scope.item = new Object();

    $scope.reloadRoute = function() {
        $route.reload();
     }

    var itens =  [
        {
            id:1,
            type: "machado",
            ataqMin:48,
            ataqMax:69,
            taxaAtaq:150,
            critico:21
        },
        {
            id:2,
            type: "garra",
            ataqMin:44,
            ataqMax:52,
            taxaAtaq:140,
            critico:12
        },
        {
            id:3,
            type: "cajado",
            ataqMin:136,
            ataqMax:146,
            taxaAtaq:170,
            bloqueio:50
        },
        {
            id:4,
            type: "foice",
            ataqMin:40,
            ataqMax:72,
            taxaAtaq:136,
            critico:19
        },
        {
            id:5,
            type: "arco",
            ataqMin:47,
            ataqMax:65,
            taxaAtaq:140,
            critico:20
        },
        {
            id:6,
            type: "espada",
            ataqMin:49,
            ataqMax:65,
            taxaAtaq:160,
            critico:22
        },
        {
            id:7,
            type: "lanca",
            ataqMin:44,
            ataqMax:58,
            taxaAtaq:134,
            critico:13
        },
        {
            id:8,
            type: "armadura",
            taxaDef:370,
            abs:9
        },
        {
            id:9,
            type: "escudo",
            taxaDef:145,
            bloqueio:23,
            abs:4.60
        },
        {
            id:10,
            type: "anel",
            taxaAtaq:80,
            taxaDef:80,
            abs:6.90,
            addHp:50,
            addMp:80,
            addSp:80,
            hpRegen:2.60,
            mpRegen:2.30
        }
    ]
    
    $scope.selecaoHome = {
        //armas
        axe:{
            id:1,
            nome:"Axes"
        },
        garra:{
            id:2,
            nome:"Garras"
        },
        cajado:{
            id:3,
            nome:"Cajados"
        },
        foice:{
            id:4,
            nome:"Foices"
        },
        arco:{
            id:5,
            nome:"Arcos"
        },
        espada:{
            id:6,
            nome:"Espadas"
        },
        lanca:{
            id:7,
            nome:"Lanças"
        },
        //defesa
        armadura:{
            id:8,
            nome:"Armaduras",
            disabled:true
        },
        escudo:{
            id:9,
            nome:"Escudos"
        },
        //acessorios
        aneis:{
            id:10,
            nome:"Anéis",
            disabled:true
        }
    }

    function onSelectItem(itemId){
        $scope.selecionado = true;

        $scope.selectedItem = getSelectedItem(itemId);
    }

    function getSelectedItem(itemId){
        var retorno;
        itens.forEach(itemUnique => {
            if(itemUnique.id === itemId){
                retorno = itemUnique;
            }
        });
        return retorno;
    }

    //secao de calculo

    $scope.niveisAge = {
        10:"+10",
        11:"+11",
        12:"+12",
        13:"+13",
        14:"+14",
        15:"+15",
        16:"+16",
        17:"+17",
        18:"+18",
        19:"+19",
        20:"+20",
        21:"+21",
        22:"+22",
        23:"+23",
        24:"+24",
    }
    $scope.niveisAgeAnel = {
        1:"+1",
        2:"+2",
        3:"+3",
        4:"+4",
        5:"+5"
    }
    function ageAnel(item){
        if(item.nivelAtual < 2){
            item.ataqMin += 3;
            item.ataqMax += 3;
            item.addHp += 30;
            item.addMana += 30;
            item.regenHp += 0.5;
            item.regenMp += 0.5;
            item.taxaDefesa += 25;
            item.absorcao += 1.0;
        }else{
            item.ataqMin += 4;
            item.ataqMax += 4;
            item.addHp += 40;
            item.addMana += 40;
            item.regenHp += 1.0;
            item.regenMp += 1.0;
            item.taxaDefesa += 30;
            item.absorcao += 2.0;
        } 
    }

    function taxaDefesaItem(item, porcento){
        var temp = 0

        var divisor = 100.00/porcento;
        var defItem = item.taxaDef;

        temp = defItem/divisor;
        item.taxaDef += temp;
        item.taxaDef = parseFloat(item.taxaDef.toFixed(2));
        if(item.nivelAtual >= 20)
            item.addHp += 50;
        
    }

    function taxaAtq(item , quantidade){
        item.taxaAtaq += quantidade;
    }

    function abs(item, quantidade){
        item.abs += quantidade;

        if(item.nivelAtual >= 10){
            item.abs += quantidade;
        }

        if(item.nivelAtual >= 20){
            item.abs += quantidade;
        }

    }

    function critico(item){
        if(item.nivelAtual % 2 === 0){
            item.critico += 1;
        }
    }

    function block(item){
        if(item.nivelAtual % 2 === 0){
            item.block += 1;
        }
        if(item.nivelAtual >= 21){
            item.block += 4;
            item.addHp += 40;
        }

    }

    function adicionarDano(item){
        item.ataqMin ++;
        item.ataqMax ++;

        if(item.nivelAtual >= 10){
            item.ataqMin ++;
            item.ataqMax ++;
        }

        if(item.nivelAtual >= 20){
            item.ataqMin ++;
            item.ataqMax ++;
        }

        if(item.nivelAtual >= 20){
            item.addHp += 20;
        }
        
    }

    function calcularAgeItem(item, niveis){
        if(niveis < 10 || niveis > 24){
            toastr.error('Nível do age deve estar entre 10 e 24','Nível do age');
            return;
        }
            

        itemJson = $scope.selectedItem;
        //item.nivelAtual = 0;
        itemJson.nivelAtual = 0;
        switch(itemJson.type){
            case "garra":
                for(var i = 0; i< niveis; i++){
                    //aumentaGarraFoiceEspada(item);
                    aumentaGarraFoiceEspada(itemJson);
                }
            break;
            case "machado":
                for(var i = 0; i< niveis; i++){
                    //aumentarMachadoEMartelo(item);
                    aumentarMachadoEMartelo(itemJson);
                }
            break;
            case "martelo":
                for(var i = 0; i< niveis; i++){
                    //aumentarMachadoEMartelo(item);
                    aumentarMachadoEMartelo(itemJson);
                }
            break;
            case "cajado":
                for(var i = 0; i< niveis; i++){
                    //aumentarCajado(item);
                    aumentarCajado(itemJson);
                }
            break;
            case "foice":
                for(var i = 0; i< niveis; i++){
                    //aumentaGarraFoiceEspada(item);
                    aumentaGarraFoiceEspada(itemJson);
                }
            break;
            case "espada":
                for(var i = 0; i< niveis; i++){
                    //aumentaGarraFoiceEspada(item);
                    aumentaGarraFoiceEspada(itemJson);
                }
            break;
            case "arco":
                for(var i = 0; i< niveis; i++){
                    //aumentarArcoLanca(item);
                    aumentarArcoLanca(itemJson);
                }
            break;
            case "lanca":
                for(var i = 0; i< niveis; i++){
                    //aumentarArcoLanca(item);
                    aumentarArcoLanca(itemJson);
                }
            break;    
            case "escudo":
                for(var i = 0; i< niveis; i++){
                    //aumentarEscudo(item);
                    aumentarEscudo(itemJson);
                }
            break;            
            case "armadura":
                for(var i = 0; i< niveis; i++){
                    //aumentarArmadura(item);
                    aumentarArmadura(itemJson);
                }
            break;
        }

        var result = compareItens(itemJson, item);
        $scope.itemCalculado = result;
        toastr.success('Item calculado com sucesso.','Item');
        return result;
    }

    function compareItens(itemCorreto, item){
        var result = {
            taxaAtaq:itemCorreto.taxaAtaq - item.taxaAtaq,
            taxaDef:itemCorreto.taxaDef - item.taxaDef,
            ataqMin:itemCorreto.ataqMin - item.ataqMin,
            ataqMax:itemCorreto.ataqMax - item.ataqMax,
            critico:itemCorreto.critico - item.critico,
            abs:itemCorreto.abs - item.abs,
            bloqueio:itemCorreto.bloqueio - item.bloqueio,
            addHp:itemCorreto.addHp - item.addHp,
            addMana:itemCorreto.addMana - item.addMana,
            addSp:itemCorreto.addSp - item.addSp,
            hpRegen:itemCorreto.hpRegen - item.hpRegen,
            mpRegen:itemCorreto.mpRegen - item.mpRegen
        }
        return result;
    }

    function aumentaGarraFoiceEspada(item){
        item.nivelAtual ++;
        adicionarDano(item);
        taxaAtq(item,5);
        critico(item);
    }

    function aumentarMachadoEMartelo(item){
        item.nivelAtual ++;
        adicionarDano(item);
        taxaAtq(item, 10);
    }

    function aumentarCajado(item){
        aumentarMachadoEMartelo(item);
        item.addMana += 10;
    }

    function aumentarArcoLanca(item){
        adicionarDano(item);
        critico(item);
    }

    function aumentarEscudo(item){
        block(item);
        abs(item,0.2);
    }

    function aumentarArmadura(item){
        item.nivelAtual++;
        taxaDefesaItem(item, 5);
        abs(item,0.5);
    }

}]);