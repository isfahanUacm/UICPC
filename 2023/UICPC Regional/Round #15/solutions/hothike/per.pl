main :-
    read_int(N), read_temps(N, W),
    solve(W, 1, 0, 50).

read_temps(0, []) :- !.
read_temps(N, [H|T]):-
    read_int(H),
    NN is N-1,
    read_temps(NN, T).

solve([T1|[T2|[T3|Rest]]], D, BestD, BestT) :-
    T is max(T1, T3),
    DD is D+1,
    (T < BestT
      -> solve([T2|[T3|Rest]], DD, D, T)
       ; solve([T2|[T3|Rest]], DD, BestD, BestT) ).
solve(_, _, BestD, BestT) :-
    writef("%d %d\n", [BestD, BestT]).


% Prolog predicates for tokenized reading from stdin.
%
% Provides the following predicates:
% read_string(S): reads a string token
% read_int(I): reads an integer token
% read_atom(A): reads an atom
%
% For all three predicates, the result is unified with end_of_file
% if the end of the input stream was reached.
%

read_string(S) :-
    read_token_codes(C),
    string_codes(S, C).

read_int(I) :-
    read_token_codes(Codes),
    (Codes == end_of_file -> I = Codes ; number_codes(I, Codes)).

read_atom(A) :-
    read_token_codes(Codes),
    (Codes == end_of_file -> A = Codes ; atom_codes(A, Codes)).


% Internal predicate for getting the next token

read_token_codes(end_of_file) :-
    peek_code(end_of_file), !.

read_token_codes(Codes) :-
    peek_code(C),
    \+ code_type(C, space), !,
    read_token_codes_helper(Codes).

read_token_codes(T) :-
    get_char(_), !,
    read_token_codes(T).


read_token_codes_helper([C0|C]) :-
    peek_code(C0),
    \+ code_type(C0, space), !,
    get_code(C0),
    read_token_codes_helper(C).

read_token_codes_helper([]).
