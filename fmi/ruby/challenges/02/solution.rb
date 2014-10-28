def render_tic_tac_toe_board_to_ascii(board)
  ascii_representation = "| "
  3.times do |i|
    ascii_representation += "#{board[i*3, 3].join(" | ")} |"
    ascii_representation += "\n| " if i < 2
  end
  ascii_representation.gsub("  ", "   ")
end
