// SPDX-License-Identifier: MIT
pragma solidity ^0.8.13;

contract MercadoriaRegistro {
    struct Mercadoria {
        string nome;
        uint quantidade;
    }

    mapping(uint => Mercadoria) public mercadorias;
    uint public numeroDeMercadorias;

    function adicionarMercadoria(uint codigo, string memory nome, uint quantidade) public {
        mercadorias[codigo] = Mercadoria(nome, quantidade);
        numeroDeMercadorias++;
    }

    function obterMercadoria(uint codigo) public view returns (string memory, uint) {
        Mercadoria memory m = mercadorias[codigo];
        return (m.nome, m.quantidade);
    }

    function removerMercadoria(uint codigo) public {
        delete mercadorias[codigo];
        numeroDeMercadorias--;
    }
}
