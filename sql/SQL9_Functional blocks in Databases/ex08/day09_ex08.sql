create function fnc_fibonacci(in pstop int default 10)
    returns table(fibonacci int) as $$
    WITH Recursive fb_nums(current_number,past_number) as(
   select 1,0
  union all
   select fb_nums.current_number+fb_nums.past_number,fb_nums.current_number
     from fb_nums
    where fb_nums.current_number<pstop
)
select past_number from fb_nums
    $$LANGUAGE sql;

select * from fnc_fibonacci(100);
select * from fnc_fibonacci();