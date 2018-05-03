angular.module('app', ['ngRoute']);

angular.module('app')
.config(function ($routeProvider) {

    $routeProvider

        // http://localhost:8080/#!/pokemon

        .when('/agecalc', {
            templateUrl: 'agecalc/index.html',
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


angular.module('app').controller('homeCtrl', function ($scope) {
  
    $scope.selecaoHome = {
        //armas
        axe:{
            id:1,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itWA510.bmp"
        },
        garra:{
            id:2,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itWC127.bmp"
        },
        cajado:{
            id:3,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itWM131.bmp"
        },
        foice:{
            id:4,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itWP506.bmp"
        },
        arco:{
            id:5,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itWS510.bmp"
        },
        espada:{
            id:6,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itWS709.bmp"
        },
        lanca:{
            id:7,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itWT161.bmp"
        },
        //defesa
        armadura:{
            id:8,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itCB733.bmp"
        },
        escudo:{
            id:9,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itDS502.bmp"
        },
        //acessorios
        aneis:{
            id:10,
            imagem:"http://xtremepk.com.br/Painel/imgs/Itens/itOR301.bmp"
        }
    }
    var teste = $scope.selecaoHome;
    console.log(typeof(teste));
    console.log($scope.selecaoHome);

});