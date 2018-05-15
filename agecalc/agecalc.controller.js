angular.module('app').controller('agecalcCtrl', function ($scope) {


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

        temp = item.taxaDefesa/(100/ porcento);
        item.taxaDefesa += temp;

        if(item.nivelAtual >= 20)
            item.addHp += 50;
        
    }

    function taxaAtq(item , quantidade){
        item.taxaAtq += quantidade;
    }

    function abs(item, quantidade){
        item.absorcao += quantidade;

        if(item.nivelAtual >= 10){
            item.absorcao += quantidade;
        }

        if(item.nivelAtual >= 20){
            item.absorcao += quantidade;
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

    console.log($scope.niveisAge);

});