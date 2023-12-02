main :-
    read_int(N), read_words(N, W),
    solve(W, 1).

read_words(0, []) :- !.
read_words(N, [H|T]):-
    read_string(H),
    NN is N-1,
    read_words(NN, T).

solve(["mumble"|T], I) :-
    II is I+1,
    solve(T, II).
solve([H|T], I) :-
    number_string(I, H),
    II is I+1,
    solve(T, II).
solve([], _) :- write("makes sense").
solve(_, _) :- write("something is fishy").


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
