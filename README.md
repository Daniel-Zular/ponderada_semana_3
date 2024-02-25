# ponderada_semana_3
Daniel Zular
### Casos de Teste para a Hash Table

1. **Inserir itens sem colisões:**
   - Adicionar `Produto(101, "Caneta BIC")` e verificar se `getLength()` retorna 1.
   - Adicionad `Produto(102, "Papel Sulfite")` e verificar se `getLength()` retorna 2.

2. **Inserir itens com colisões (assumindo que a função de hash possa causar colisões):**
   - Inserir `Produto(201, "Lápis")` e `Produto(301, "Borracha")`, ambos no mesmo lugar. Verificar se ambos estão na tabela e `getLength()` aumentou corretamente.

3. **Buscar itens:**
   - Buscar pelos produtos inseridos acima e verificar se são encontrados corretamente.

4. **Deletar itens:**
   - Deletar `Produto(101, "Caneta BIC")` e verificar se `getLength()` diminuiu.
   - Tentar buscar pelo produto deletado e verificar que não é mais encontrado.

5. **Tentativa de inserção em uma tabela cheia:**
   - Continuar inserindo itens até que `isFull()` retorne verdadeiro (ou seja, que deu o limite).
   - Tentar inserir outro item e ver que não é possível.
